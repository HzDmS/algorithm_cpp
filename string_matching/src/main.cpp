#include<iostream>
#include<string>
#include<vector>

typedef std::shared_ptr<std::vector<int>> mytype;

mytype partial(std::string& pattern) {

    int n = pattern.size();
    mytype lookup_vec = std::make_shared<std::vector<int>> (n, 0);

    for (int i = 1; i < n; i++) {
        int k = lookup_vec -> at(i - 1);
        while (k > 0 && pattern[i] != pattern[k]) {
            k = lookup_vec -> at(k - 1);
        }
        if (pattern[i] == pattern[k]) {
            k++;
        }
        lookup_vec -> at(i) = k;
    }

    return lookup_vec;
}

std::vector<int> search(std::string& text, std::string& pattern) {
    int m = text.size();
    int n = pattern.size();
    std::vector<int> res;

    mytype lookup_vec = partial(pattern);

    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j > 0 && pattern[j] != text[i]) {
            j = lookup_vec -> at(j - 1);
        }

        if (pattern[j] == text[i]) {
            j++;
        }

        if (j == n) {
            res.push_back(i - n + 1);
            j = lookup_vec -> at(j - 1);
        }
    }

    return res;
}

int main() {
    std::string text = "asdfasdfasdfasdfasdgagasdfadsf";
    std::string pattern = "asd";
    std::vector<int> positions = search(text, pattern);

    for (auto i = positions.begin(); i != positions.end(); i++) {
        std::cout << "Mathced at position: " << *i << std:: endl;
    } 
    return 0;
}