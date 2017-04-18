#include<cstdio>
#include<cstdlib>
#include<random>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

/*********************************
 * Testdata generating utilities *
 * By bigelephant29              *
 *********************************/

const int PROBLEM_NO = 17020801;
const int TESTDATA_COUNT = 100;

mt19937 rng(0x5EED);
int randint(int lb, int ub) {
    /* randomly generate number in [lb, ub] */
    return uniform_int_distribution<int>(lb, ub)(rng);
}

string intToStr(int num) {
    string ret = "";
    while(num) {
        ret += num % 10 + '0';
        num /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string getFileName(int prob_no, int data_no, bool sample, const string& suffix = "") {
    string ret = "testdata/";
    if(sample) {
        ret += intToStr(prob_no) + ".sample";
        //ret += data_no - 1 + 'a';
        ret += suffix;
    } else {
        ret += intToStr(prob_no) + ".";
        ret += intToStr(data_no) + suffix;
    }
    return ret;
}

string getFileInName(int prob_no, int data_no, bool sample) {
    return getFileName(prob_no, data_no, sample, ".in");
}

string getFileOutName(int prob_no, int data_no, bool sample) {
    return getFileName(prob_no, data_no, sample, ".out");
}

void genOut(const string& in, const string& out) {
    char cmd[256];
    sprintf(cmd, "./solve < %s > %s", in.c_str(), out.c_str());
    system(cmd);
}

void writeFileLog(const string& file_name) {
    fprintf(stderr, "Generating [%s] ...", file_name.c_str());
}

void writeFinished() {
    fprintf(stderr, "Finished.\n");
}


int main() {
    
    FILE *fp;
    string fn_in, fn_out;
    
    // sample
    writeFileLog( getFileName(PROBLEM_NO, 1, true) );
    fn_in = getFileInName(PROBLEM_NO, 1, true);
    fn_out = getFileOutName(PROBLEM_NO, 1, true);
    fp = fopen(fn_in.c_str(), "w");
    fprintf(fp, "72\n");
    fclose(fp);
    genOut(fn_in, fn_out);
    writeFinished();
    
    for(int i = 1 ; i <= TESTDATA_COUNT ; i++) {
        writeFileLog( getFileName(PROBLEM_NO, i, false) );
        fn_in = getFileInName(PROBLEM_NO, i, false);
        fn_out = getFileOutName(PROBLEM_NO, i, false);
        fp = fopen(fn_in.c_str(), "w");

        int n;
        if(i == 1) n = 1;
        else if(i == 2) n = 1073741824;
        else {
            do {
                n = abs(randint(2, INT_MAX)<<randint(0, 25));
            } while(n == 0);
        }
        fprintf(fp, "%d\n", n);

        fclose(fp);
        genOut(fn_in, fn_out);
        writeFinished();
    }

    return 0;
}
