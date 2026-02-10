// huffman_decoder.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <sstream>

using namespace std;

struct HuffmanNode {
    char ch;
    shared_ptr<HuffmanNode> left, right;
    
    HuffmanNode(char c) : ch(c), left(nullptr), right(nullptr) {}
};

class HuffmanDecoder {
private:
    shared_ptr<HuffmanNode> root;
    size_t treeIndex;
    
    // 反序列化哈夫曼树
    shared_ptr<HuffmanNode> deserializeTree(const string& treeStr) {
        if (treeIndex >= treeStr.length()) {
            return nullptr;
        }
        
        char current = treeStr[treeIndex++];
        
        if (current == '1') {
            // 叶子节点
            if (treeIndex >= treeStr.length()) {
                cerr << "Error: Unexpected end of tree string" << endl;
                return nullptr;
            }
            char ch = treeStr[treeIndex++];
            return make_shared<HuffmanNode>(ch);
        } else if (current == '0') {
            // 内部节点
            auto node = make_shared<HuffmanNode>('\0');
            node->left = deserializeTree(treeStr);
            node->right = deserializeTree(treeStr);
            return node;
        }
        
        cerr << "Error: Invalid tree format" << endl;
        return nullptr;
    }
    
public:
    HuffmanDecoder() : treeIndex(0) {}
    
    // 解码函数
    string decode(const string& treeStr, const string& encodedText) {
        treeIndex = 0;
        root = deserializeTree(treeStr);
        
        if (!root) {
            cerr << "Error: Failed to build Huffman tree" << endl;
            return "";
        }
        
        string decodedText;
        auto current = root;
        
        for (char bit : encodedText) {
            if (bit == 'c') {
                current = current->left;
            } else if (bit == 'C') {
                current = current->right;
            } else {
                // 跳过无效字符
                continue;
            }
            
            if (!current) {
                cerr << "Error: Invalid encoded text - reached null node" << endl;
                return "";
            }
            
            // 如果是叶子节点，输出字符并回到根节点
            if (!current->left && !current->right) {
                decodedText += current->ch;
                current = root;
            }
        }
        
        // 检查是否在中间节点结束（不完整的编码）
        if (current != root) {
            cerr << "Warning: Encoded text ended at non-leaf node" << endl;
        }
        
        return decodedText;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input.encoded> <output.cpp>\n";
        return 1;
    }
    
    string inputFile = argv[1];
    string outputFile = argv[2];
    
    // 读取编码文件
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Cannot open input file " << inputFile << "\n";
        return 1;
    }
    
    string line;
    string treeStr, encodedText;
    bool readingTree = false;
    bool readingData = false;
    
    while (getline(inFile, line)) {
        if (line.find("TREE:") == 0) {
            treeStr = line.substr(5);
            readingTree = true;
        } else if (line.find("DATA:") == 0) {
            encodedText = line.substr(5);
            readingData = true;
        } else if (readingData) {
            // 移除编码器添加的换行符
            encodedText += line;
        }
    }
    inFile.close();
    
    if (treeStr.empty()) {
        cerr << "Error: Tree data not found in input file" << endl;
        return 1;
    }
    
    if (encodedText.empty()) {
        cerr << "Error: Encoded data not found in input file" << endl;
        return 1;
    }
    
    cout << "Tree string length: " << treeStr.length() << endl;
    cout << "Encoded text length: " << encodedText.length() << endl;
    
    // 解码
    HuffmanDecoder decoder;
    string decodedText = decoder.decode(treeStr, encodedText);
    
    if (decodedText.empty()) {
        cerr << "Error: Decoding failed" << endl;
        return 1;
    }
    
    // 保存解码结果
    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error: Cannot create output file " << outputFile << "\n";
        return 1;
    }
    
    outFile << decodedText;
    outFile.close();
    
    cout << "Decoding completed. Output saved to " << outputFile << "\n";
    cout << "Decoded size: " << decodedText.size() << " characters\n";
    
    return 0;
}