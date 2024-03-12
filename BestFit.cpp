#include <bits/stdc++.h>
using namespace std;

struct Blocks {
    int block_no = 0, block_size = 0, file_no = 0, file_size = 0,
    fragmentation = 0;
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
    // BEST FIT ALGORITHM
    for(int i=0; i<nf; i++) {
        int file_size = files[i];
        // Traverse the blocks array
        vector<struct Blocks> v; 
        for(int j=0; j<nb; j++) {
            if((blocks[j].block_size >= file_size) && (blocks[j].file_no == 0)) {
               v.push_back(blocks[j]);
            }
        }
        cout << "File " << i+1 << endl;
        cout << "Probable Block No: "; 
        for(int t=0; t<v.size(); t++) {
            cout << v[t].block_no << " ";
        }
        cout << endl;
        // Which block is Minimum
        int minBlock = v.size() > 0 ? v[0].block_no : -1;
        for(int m=1; m<v.size(); m++) {
            if(v[m].block_size <= v[minBlock-1].block_size) {
                minBlock = v[m].block_no;
            }
        }
        cout << "MinBlock: " << minBlock << endl;
        if(minBlock == -1) continue;
        minBlock = minBlock-1;
        //Occupy the block
        blocks[minBlock].file_no = i+1;
        blocks[minBlock].file_size = file_size;
        blocks[minBlock].fragmentation = blocks[minBlock].block_size - file_size;
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