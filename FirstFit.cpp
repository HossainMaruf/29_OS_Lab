#include <bits/stdc++.h>
using namespace std;

struct Blocks {
    int block_no = 0;
    int block_size = 0;
    int file_no = 0;
    int file_size = 0;
    int fragmentation = 0;
};

int main()
{
    freopen("ff.txt", "r", stdin);
    int nb, nf;
    cin >> nb;
    struct Blocks blocks[nb];
    // Input of Block Information
    for (int i = 0; i < nb; i++) {
        cin >> blocks[i].block_size;
        blocks[i].block_no = i+1;
    }

    // Input of File Information
    cin >> nf;
    int files[nf];
    for(int i=0; i<nf; i++) {
        cin >> files[i];
    }
    // FIRST FIT ALGORITHM
    for(int i=0; i<nf; i++) {
        int file_size = files[i];
        for(int j=0; j<nb; j++) {
           if((blocks[j].block_size >= file_size) && (blocks[j].file_no == 0)) {
            // allocated
            blocks[j].file_no = i+1;
            blocks[j].file_size = file_size;
            blocks[j].fragmentation = blocks[j].block_size - file_size;
            break;
           } 
        }
    }


    // Print Table (Memory State)
    cout << "BlockNo\tBlockSize\tFileNo\tFileSize\tFragmentation" << endl;
    for (int i = 0; i < nb; i++)
    {
        cout << blocks[i].block_no << "\t" <<
        blocks[i].block_size << "\t\t" <<  
        blocks[i].file_no << "\t\t" << 
        blocks[i].file_size << "\t\t" << 
        blocks[i].fragmentation << endl;
    }
    return 0;
}