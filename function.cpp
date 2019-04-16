#pragma once
#include<iostream>
using std::ostream; using std::cout; using std::cin;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;
#include <stdlib.h>
using namespace std;
//#include "proj06/proj06_functions.h"


ostream& print_vector(const vector<long>& v, ostream& out){
    for(int i=0 ;i<v.size();++i){
        if(i < v.size()-1){
            out << v[i]<<',' ;
        }
        else{
            out << v[i];
        }
    }
    return out;
}// print oss string.

long four_corner_sum(const vector<long>& v,int rows, int cols){
    if (v.size() >2){
        long sum_num,f_con,s_con,t_con,fo_con;
        long f_num, s_num, t_num, fo_num;
        f_con = 0;
        f_num=v[f_con];
        s_con = f_con + cols-1;
        s_num = v[s_con];
        t_con= (rows-1)*cols+0;
        t_num= v[t_con];
        fo_con= t_con+cols-1;
        fo_num= v[fo_con];
        sum_num=f_num +s_num+t_num+fo_num;
        return sum_num;
    }
    else {
        return 0;
    }
}//get the four corners' value and sum of these.

vector<long> column_order(const vector<long>& v, int rows, int cols){
    vector<long> result;
    long num;
    for (int i=0; i< cols; ++i){
        for (int a =0; a<rows; ++a){
            num= a*cols + i;
            result.push_back(v[num]);
        }
    }

    return result;
}//change the column order.

vector<long> rotate_rows_up(const vector<long>& v, int rows, int cols){
    //vector<long> result;

    if (v.size() <2 || rows <2){
        vector<long> result;
        return result;
    }
    if(rows >= 2){
        long num, num2;
        vector<long> result(rows*cols+cols-cols,0);
        for(int i = 0; i<rows; i++){
            for(int j=0;j<cols;j++){
                if(i == 0){
                    num = (rows-1)*cols +j;
                    num2= i*cols+j;
                    result[num]=v[num2];
                    //first_row.push_back(v[i*cols+j]);
                }
                else{
                    num=(i-1)*cols+j;
                    num2=i*cols+j;
                    result[num]=v[num2];
                }
            }
        }
        return result;
    }

}//rotate the rows. if row ==0, tuen this to the last row. if the row>0, tuen the row to the upeer one.

vector<long> matrix_ccw_rotate(const vector<long>&v, int rows, int cols){
    vector<long> num;
    vector<long> old_matrix = column_order(v,rows,cols);
    for(int i = cols-1; i>=0; i--){
        long word;
        for(int j=0;j<rows;j++){
            word = i*rows +j;
            num.push_back(old_matrix[word]);
        }
    }
    return num;
}// rotate the matrix to clockwise 90 degree.

long max_column_diff(const vector<long>& v, int rows, int cols){
    if (v.size() <cols+1 ||v.size() <4){
        return 0;
    }
    else {
        long num;
        vector<long> result, vec;
        for (int i = 0; i < cols; ++i) {
            long sum_col = 0;
            for (int a = 0; a < rows; ++a) {
                num = a * cols + i;
                sum_col += v[num];
            }
            result.push_back(sum_col);
        }
        sort(result.begin(), result.end());
        long num_diff;
        for (int a = 1; a < cols; ++a) {
            num_diff = result[a] - result[a - 1];
            vec.push_back(num_diff);

        }
        /*long max_num=-100000;
        for (auto c : vec){
            if (c>max_num){
                max_num=c;
            }
        }*/
        long new_num = 0;
        for (auto c: vec) {
            new_num += c;
        }
        return new_num;
    }
}// get the sum of eachcolumn and compare the difference then return the max difference.

long trapped_vals(const vector<long>& v, int rows, int cols){
    long count_num=0;
    for (int i=0; i<rows; ++i){
        for (int a=0; a<cols; ++a){
            long num0, numle, numri, numup, numdow, k,b,c,d,e;
            if ((i+1) <rows &&  -1< (i-1) && (a-1) >-1 && (a+1) <cols){
                num0 = i*cols +a;
                numle = i*cols +a -1;
                numri = i*cols + a +1;
                numup = (i-1)*cols +a;
                numdow= (i+1)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }//central

            if ((i+1) <rows &&  -1<(i-1) && (a-1) >-1 && (a+1) >cols) {
                num0 = i*cols +a;
                numle = i*cols +a -1;
                numri = i*cols + a -a;
                numup = (i-1)*cols +a;
                numdow= (i+1)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }//right
            if ((i+1) <rows &&  -1<(i-1) && (a-1) <0 && (a+1) <cols){
                num0 = i*cols +a;
                numle = i*cols +cols-1;
                numri = i*cols + a +1;
                numup = (i-1)*cols +a;
                numdow= (i+1)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }//left
            if((i+1) >rows-1 &&  -1<(i-1) && (a-1) >-1 && (a+1) <cols){
                num0 = i*cols +a;
                numle = i*cols +a -1;
                numri = i*cols + a +1;
                numup = (i-1)*cols +a;
                numdow= (i-i)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }//down
            if ((i+1) <rows &&  (i-1)<0 && (a-1) >-1 && (a+1) <cols){
                num0 = i*cols +a;
                numle = i*cols +a -1;
                numri = i*cols + a +1;
                numup = (rows-1)*cols +a;
                numdow= (i+1)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }
            //upper
            if ((i+1) <rows &&  (i-1)<0 && (a-1) <0 && (a+1) <cols){
                num0 = i*cols +a;
                numle = i*cols +cols-1;
                numri = i*cols + a +1;
                numup = (rows-1)*cols +a;
                numdow= (i+1)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }
            // left up conner
            if ((i+1) <rows &&  (i-1)<0 && (a-1) >-1 && (a+1) >cols-1){
                num0 = i*cols +a;
                numle = i*cols +a-1;
                numri = i*cols + a -a;
                numup = (rows-1)*cols +a;
                numdow= (i+1)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }
            // right up conner
            if ((i+1) >rows-1 &&  (i-1)>-1 && (a-1) <0 && (a+1) <cols){
                num0 = i*cols +a;
                numle = i*cols +cols-1;
                numri = i*cols + a +1;
                numup = (i-1)*cols +a;
                numdow= (i-i)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }
            //left down conner
            if ((i+1) >rows-1 &&  (i-1)>-1 && (a-1) >-1 && (a+1) >cols-1){
                num0 = i*cols +a;
                numle = i*cols +a-1;
                numri = i*cols + a -a;
                numup = (i-1)*cols +a;
                numdow= (i-i)*cols+a;
                k=v[num0];
                b=v[numle];
                c=v[numri];
                d=v[numup];
                e=v[numdow];
                if ( b>k && c>k && d>k && e>k){
                    count_num +=1;
                }
            }
            // right down conner
        }
    }
    return count_num;
}// get the trapped value.
