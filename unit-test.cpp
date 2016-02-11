#include "codec.h"
#include <cassert>
#include <sstream>

using namespace std;

int test_empty_file(void) {
    ifstream test_in;
    ofstream test_out;

    test_in.open("empty_file.txt");
    test_out.open("result.bin", ios::binary | ios::trunc);

    return encode(test_in, test_out);
}

int test_out_of_range(void) {
    ifstream test_in;
    ofstream test_out;

    test_in.open("out_of_range.txt");
    test_out.open("result.bin", ios::binary | ios::trunc);

    return encode(test_in, test_out);
}

int test_empty_lines(void) {
    ifstream test_in;
    ofstream test_out;

    test_in.open("empty_lines.txt");
    test_out.open("result.bin", ios::binary | ios::trunc);

    return encode(test_in, test_out);
}

int test_with_words(void) {
    ifstream test_in;
    ofstream test_out;

    test_in.open("with_words.txt");
    test_out.open("result.bin", ios::binary | ios::trunc);

    return encode(test_in, test_out);
}

int test_positive(void) {
    ifstream test_in;
    ofstream test_out;

    test_in.open("positive.txt");
    test_out.open("result.bin", ios::binary | ios::trunc);

    return encode(test_in, test_out);
}

int test_decode_empty(void) {
    ifstream test_in;
    ofstream test_out;

    test_in.open("empty_file.txt", ios::binary);
    test_out.open("result2.txt");

    return decode(test_in, test_out);
}

int test_invalid_file(void) {
    ifstream test_in;
    ofstream test_out;

    test_in.open("invalid_file.bin", ios::binary);
    test_out.open("result2.txt", ios::trunc);

    return decode(test_in, test_out);
}

int test_decode_positive(void) {
    ifstream test_in;
    ofstream test_out;

    test_in.open("result.bin", ios::binary);
    test_out.open("result2.txt", ios::trunc);

    return decode(test_in, test_out);
}

int main(void) {

    //encode: test with empty file
    assert(test_empty_file());
    //encode: test with out_of_range number
    assert(test_out_of_range());
    //encode: test with empty lines
    assert(test_empty_lines());
    //encode: test with words
    assert(test_with_words());
    //encode: positive test
    assert(test_positive() == 0);

    //decode: test with empty file
    assert(test_decode_empty());
    //decode: test with invalid file
    assert(test_invalid_file());
    //decode: positive test
    assert(test_decode_positive() == 0);

    //check file sizes
    ifstream origin;
    ifstream result;

    origin.open("positive.txt");
    result.open("result2.txt");

    origin.seekg(0, ios::end);
    result.seekg(0, ios::end);
    streamoff origin_size = origin.tellg();
    streamoff result_size = result.tellg();

    assert(origin_size == result_size);
}
