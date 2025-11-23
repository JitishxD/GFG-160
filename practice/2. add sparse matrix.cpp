#include <iostream>
#include <vector>

using namespace std;

struct sparse {
    int m;
    int n;
    int num;
    struct element* e;
};

struct element {
    int i;
    int j;
    int x;
};

struct sparse* add(struct sparse* s1, struct sparse* s2) {
    struct sparse* sum;
    int i, j, k;
    i = j = k = 0;

    if (s1->m != s2->m || s1->n != s2->n) return NULL;

    sum = new sparse;
    sum->e = new element[s1->num + s2->num];

    while (i < s1->num && j < s2->num) {
        if (s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if (s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else {
            if (s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }

    for (; i < s1->num; i++) sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++) sum->e[k++] = s2->e[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

void display(struct sparse s) {
    int i, j, k = 0;
    for (i = 0; i < s.m; i++) {
        for (j = 0; j < s.n; j++) {
            if(i == s.e[k].i && j == s.e[k].j) {
                cout << s.e[k].x << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    struct sparse* s1 = new sparse;
    struct sparse* s2 = new sparse;
    struct sparse* sum = new sparse;
    s1->m = 5;
    s1->n = 5;  
    s1->num = 5;
    s1->e = new element[s1->num];
    s1->e[0] = {0, 0, 5};
    s1->e[1] = {1, 3, 8};
    s1->e[2] = {2, 1, 9};
    s1->e[3] = {3, 4, 6};
    s1->e[4] = {4, 2, 7};
    s2->m = 5;
    s2->n = 5;
    s2->num = 5;
    s2->e = new element[s2->num];
    s2->e[0] = {0, 1, 3};
    s2->e[1] = {1, 3, 5};
    s2->e[2] = {2, 2, 4};
    s2->e[3] = {3, 0, 2};
    s2->e[4] = {4, 4, 1};
    sum = add(s1, s2);
    cout << "First Matrix: " << endl;
    display(*s1);
    cout << "Second Matrix: " << endl;
    display(*s2);
    cout << "Sum Matrix: " << endl;
    display(*sum);

    return 0;
}