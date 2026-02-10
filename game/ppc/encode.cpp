// huffman_encoder.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>

using namespace std;

// 哈夫曼树节点
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;
    
    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// 比较函数用于优先队列
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

class HuffmanEncoder {
private:
    unordered_map<char, string> huffmanCodes;
    HuffmanNode* root;
    
    // 构建频率表
    unordered_map<char, int> buildFrequencyTable(const string& text) {
        unordered_map<char, int> freq;
        for (char ch : text) {
            freq[ch]++;
        }
        return freq;
    }
    
    // 构建哈夫曼树
    HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& freq) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
        
        for (auto& pair : freq) {
            pq.push(new HuffmanNode(pair.first, pair.second));
        }
        
        while (pq.size() > 1) {
            HuffmanNode* left = pq.top(); pq.pop();
            HuffmanNode* right = pq.top(); pq.pop();
            
            HuffmanNode* parent = new HuffmanNode('\0', left->freq + right->freq);
            parent->left = left;
            parent->right = right;
            
            pq.push(parent);
        }
        
        return pq.top();
    }
    
    // 生成哈夫曼编码
    void generateCodes(HuffmanNode* node, const string& code) {
        if (!node) return;
        
        if (!node->left && !node->right) {
            huffmanCodes[node->ch] = code;
            return;
        }
        
        generateCodes(node->left, code + "c");
        generateCodes(node->right, code + "C");
    }
    
    // 序列化哈夫曼树
    string serializeTree(HuffmanNode* node) {
        if (!node) return "";
        
        if (!node->left && !node->right) {
            return "1" + string(1, node->ch);
        }
        
        return "0" + serializeTree(node->left) + serializeTree(node->right);
    }
    
    // 辅助函数：获取字符的可读表示
    string getCharRepresentation(char ch) {
        switch (ch) {
            case '\n': return "\\n";
            case '\t': return "\\t";
            case '\r': return "\\r";
            case ' ': return "space";
            default: return string(1, ch);
        }
    }
    
public:
    HuffmanEncoder() : root(nullptr) {}
    
    ~HuffmanEncoder() {
        // 清理内存 - 实际应用中应该用智能指针
        // 这里简化处理
    }
    
    // 编码函数
    pair<string, string> encode(const string& text) {
        // 构建频率表和哈夫曼树
        auto freq = buildFrequencyTable(text);
        root = buildHuffmanTree(freq);
        
        // 生成编码
        generateCodes(root, "");
        
        // 序列化树
        string treeSerialized = serializeTree(root);
        
        // 编码文本
        string encodedText;
        for (char ch : text) {
            encodedText += huffmanCodes[ch];
        }
        
        return {treeSerialized, encodedText};
    }
    
    // 保存编码结果到文件
    void saveToFile(const string& filename, const string& tree, const string& encodedText) {
        ofstream outFile(filename);
        
        if (!outFile) {
            cerr << "Error: Cannot create output file " << filename << "\n";
            return;
        }
        
        // 写入树结构
        outFile << "TREE:" << tree << "\n";
        
        // 写入编码后的文本
        outFile << "DATA:";
        
        // 每80个字符换行，便于阅读
        for (size_t i = 0; i < encodedText.size(); i++) {
            outFile << encodedText[i];
            if ((i + 1) % 80 == 0) outFile << "\n";
        }
        
        outFile.close();
    }
    
    // 打印编码表
    void printCodeTable() {
        cout << "Huffman Code Table:\n";
        for (auto& pair : huffmanCodes) {
            cout << "'" << getCharRepresentation(pair.first) 
                 << "' -> " << pair.second << "\n";
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input.cpp> <output.encoded>\n";
        return 1;
    }
    
    string inputFile = argv[1];
    string outputFile = argv[2];
    
    // 读取输入文件
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Cannot open input file " << inputFile << "\n";
        return 1;
    }
    
    string content((istreambuf_iterator<char>(inFile)), 
                   istreambuf_iterator<char>());
    inFile.close();
    
    if (content.empty()) {
        cerr << "Error: Input file is empty\n";
        return 1;
    }
    
    // 编码
    HuffmanEncoder encoder;
    auto result = encoder.encode(content);
    string tree = result.first;
    string encodedText = result.second;
    
    // 保存结果
    encoder.saveToFile(outputFile, tree, encodedText);
    
    // 打印统计信息
    cout << "Original size: " << content.size() << " characters\n";
    cout << "Encoded size: " << encodedText.size() << " bits (" 
         << (encodedText.size() + 7) / 8 << " bytes)\n";
    cout << "Compression ratio: " 
         << (double)(encodedText.size()) / (content.size() * 8) * 100 << "%\n";
    
    encoder.printCodeTable();
    
    cout << "Encoding completed. Output saved to " << outputFile << "\n";
    
    return 0;
}