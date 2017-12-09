#include "stdio.h"  
#include "stdlib.h"
#include <string.h>  
#include <math.h>  
#include <iostream> 
#include <algorithm>  
#include <vector>  
using namespace std;
#define MAX  10005

class Solution {
	private:
		int next[MAX];
		string text;
		string pattern;
	public:
		void calcNext() {
			next[0] = -1;
			int k = -1;
			int j = 0;
			while (j < pattern.length()-1) {
				if (k==-1 || pattern[j]==pattern[k]) {
					//��ʼ�������ʱ������
					k++;
					j++;
					next[j] = k;
				} else {
					//��ƥ��,������ǰ�ݹ�
					k = next[k];
				}
			}
		}

		void calcNextEx() {
			next[0] = -1;
			int k = -1;
			int j = 0;
			while (j < pattern.length()-1) {
				if (k==-1 || pattern[j]==pattern[k]) {
					//��ʼ�������ʱ������
					k++;
					j++;
					//���������ж��Ƿ���ϴ���ͬ
					if (pattern[j] == pattern[k]) {
						next[j] = next[k];
					} else {
						next[j] = k;
					}
				} else {
					//��ƥ��,������ǰ�ݹ�
					k = next[k];
				}
			}
		}

		int KMP() {
			this->calcNextEx();
			int ans = -1;
			int i = 0;
			int j = 0;
			int text_len = text.length();
			int pattern_len = pattern.length();
			while (i < text_len) {
				if (j==-1 || text[i]==pattern[j]) {
					//��ʼ�����������Ӵ�ƥ������
					i++;
					j++;
				} else {
					//�Ӵ���ƥ���򻬶�
					j = next[j];
				}
				if (j == pattern_len) {
					ans = i - pattern.length();
					break;
				}
			}
			return ans;
		}

		int strStr(string haystack, string needle) {
			text = haystack;
			pattern = needle;
			if (needle.empty())
        		return 0;
			if (haystack.empty())
        		return -1;
    		return this->KMP();
		}
};

int main(void)  
{  

}  