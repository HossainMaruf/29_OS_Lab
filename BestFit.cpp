#include <bits/stdc++.h>
using namespace std;

struct Blocks {
    int block_no = 0, block_size = 0, file_no = 0, file_size = 0,
    fragmentation = 0;
};

int main()
{
    freopen("PartitionData.txt", "r", stdin);
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
        int minBlock = -1;
        vector<struct Blocks> v; 
        for(int j=0; j<nb; j++) {
            if((blocks[j].block_size >= file_size) && (blocks[j].file_no == 0)) {
               v.push_back(blocks[j]);
               if(minBlock == -1) {
                // First satisfied block
                minBlock = v[0].block_no;
               } else {
                // This is not the first block
                    if(v[v.size()-1].block_size < blocks[minBlock-1].block_size) {
                        minBlock = v[v.size()-1].block_no;
                    }
               }
            }
        }
        cout << "File " << i+1 << endl;
        cout << "Probable Block No: "; 
        for(int t=0; t<v.size(); t++) {
            cout << v[t].block_no << " ";
        }
        cout << endl;
        /**
         * 
        // Which block is Minimum
        // int minBlock = -1;
        // if(v.size() > 0) {
        //     minBlock = v[0].block_no;
        //     for(int m=1; m<v.size(); m++) {
        //         if((v[m].block_size < blocks[minBlock-1].block_size) && (v[m].file_no == 0)) {
        //             minBlock = v[m].block_no;
        //         }
        //     }
        // }
        // cout << "MinBlock: " << minBlock << endl;
         * 
        */

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