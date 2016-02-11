#include "codec.h"

using namespace std;

int encode(ifstream &in, ofstream &out) {
    uint64_t symbols_count = 0;
    uint64_t bytes_count = 0;
    uint32_t exp_result;
    const streamsize exp_res_size = sizeof(exp_result);

    size_t pos;

    //check size, must be 4*x
    in.seekg(0, ios::end);
    streamoff file_size = in.tellg();
    if(file_size <= 0) {
        cerr << "Encode: Invalid input file" << std::endl;
        return 1;
    }
    in.seekg(0, ios::beg);

    for(string line; getline(in, line);) {
        symbols_count += line.length() + 1;

        try {

            unsigned long res = stoul(line, &pos, 10);
            //x64 linux has 64bit long, so add out of range check
            if(res > UINT32_MAX) {
                cerr << "Encode: Invalid result of an experiment(number out of range))" << std::endl;
                return 1;
            }

            exp_result = (uint32_t)res;
        } catch(invalid_argument e) {
            cerr << "Encode: Invalid result of an experiment(not а number)" << std::endl;

            return 1;
        } catch (out_of_range  e) {
            cerr << "Encode: Invalid result of an experiment(number out of range))" << std::endl;

            return 1;
        }

        out.write(reinterpret_cast<const char *>(&exp_result), exp_res_size);
        bytes_count += 4;
    }

    cout << "Was read " << symbols_count << " symbols and write " << bytes_count << " bytes" << endl;
    return 0;
}

int decode(ifstream &in, ofstream &out)  {
    uint64_t symbols_count = 0;
    uint64_t bytes_count = 0;
    uint32_t exp_result;
    const streamsize exp_res_size = sizeof(exp_result);

    //check size, must be 4*x
    in.seekg(0, ios::end);
    streamoff file_size = in.tellg();
    if(file_size % 4 != 0 || file_size <= 0) {
        cerr << "Decode: Invalid input file" << std::endl;
        return 1;
    }
    in.seekg(0, ios::beg);

    while(bytes_count != file_size) {
        in.read(reinterpret_cast<char *>(&exp_result), exp_res_size);
        bytes_count += 4;

        string str = to_string(exp_result);
        symbols_count += str.length() + 1;
        out << str << endl;
    }

    cout << "Was read " << bytes_count << " bytes and write " << symbols_count << " symbols" << endl;
    return 0;
}
