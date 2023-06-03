#include<iostream>
#include<set>

int main() {
    using namespace std;
    set<int> s{};

    s.insert(2);
    s.insert(3);

    cout<<s.erase(2)<<endl;
    cout<<s.erase(5)<<endl;

    return 0;
}
