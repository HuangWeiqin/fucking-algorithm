
#include <iostream>
#include <vector>

//递归体， 递归假设: 该函数将分割数字n为无重复的升序的数字组合，且这些数字组合最末尾数字即最大值为lb，所有数字组合将存入sp中 
void Rec_getAllSplit(int n,int lb ,std::vector<std::vector<int> > &sp) {
    if (n <= 1) {
        std::vector<int> tmp;
        tmp.push_back(1);
        sp.push_back(tmp);
        return;
    }

    if (lb == 1) {
        std::vector<int> tmp;
        for(int i = 0; i < n; ++i ){
            tmp.push_back(1);
        }
        sp.push_back(tmp);
        return;
    }

    for (int i = 1; i <= std::min(lb,n-1); ++i) {
        std::vector<std::vector<int> > tmp_sp;
        Rec_getAllSplit(n - i, i, tmp_sp); //仔细思考为什么这样的递归假设可以从儿子构造出老子，好好感受 升序! 的重要性
        for (std::vector<int>& vt : tmp_sp) {
            vt.push_back(i);
            sp.push_back(vt); 
        }
    }

}


void pf(std::vector<std::vector<int> > &res) {

    for (std::vector<int>& vt : res) {
        for (int i : vt) {
        std::cout << i << ' ';
        }
        std::cout <<std::endl;
    }

}

void getAllSplit(int n) {
    std::vector<std::vector<int> > res;
    Rec_getAllSplit(n, n-1, res);
    pf(res);
}



int main()
{
    getAllSplit(10);
}
