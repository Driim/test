#include "codec.h"

using namespace std;

void print_usage(void) {
    cerr << "Yandex Test \n"
         << "Usage:\n\t"
         << "Test -e in.txt out.bin to encode\n\t"
         << "Test -d in.bin out.txt to decode\n\t";
}

int main(int argc, char *argv[]) {
    int result = 1;
    ifstream in;
    ofstream out;

    if(argc < 4) {
        print_usage();
        return 0;
    }

    string op(argv[1]);

    if(string("-e").compare(op) == 0) {
        in.open(argv[2]);
        if(!in.good()) {
            cerr << "I can not open input file" << endl;
            return 1;
        }

        out.open(argv[3], ios::binary | ios::trunc);
        if(!out.good()) {
            cerr << "I can not open output file" << endl;
            return 1;
        }
        result = encode(in, out);
    } else if(string("-d").compare(op) == 0) {
        in.open(argv[2], ios::binary);
        if(!in.good()) {
            cerr << "Decode: I can not open input file" << endl;
            return 1;
        }

        out.open(argv[3], ios::trunc);
        if(!out.good()) {
            cerr << "Decode: I can not open output file" << endl;
            return 1;
        }
        result = decode(in, out);
    } else {
        cerr << "Invalid argument" << std::endl ;
        print_usage();
        return 1;
    }

    return result;
}