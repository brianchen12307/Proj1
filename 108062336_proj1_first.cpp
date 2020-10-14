#include<iostream>
#include<fstream>
#include<map>
using namespace std;

class Point{
    public:
        Point(int xi = 0, int yi = 0, int op = 0){
            x= xi;
            y = yi;
            ocup = op;
        }
        Point(const Point& pt){
            x = pt.x;
            y = pt.y;
            ocup = pt.ocup;
        }
        int x, y, ocup;
};

class Rec{
    public:
        Rec(int in_row, int in_col){
            row = in_row;
            col = in_col;

            board = new Point*[in_row];
            for(int i = 0;i < in_row;i++)
                board[i] = new Point[in_col];

            for(int i = 0; i < in_row;i++){
                for(int j = 0;j < in_col;j++){
                    Point tmp(i + 1, j + 1,0);
                    board[i][j] = tmp;
                }
            }
        }
        void check_eliminate(){
            int check;
            for(int i = 0;i < row;i++){
                check = 1;
                for(int j = 0;j < col;j++){
                    check = check & board[i][j].ocup;
                }
                if(check){
                    for(int k = i;k >= 0;k--){
                        for(int s = 0;s < col;s++){
                            if(!k)
                                board[k][s].ocup = 0;
                            else 
                                board[k][s].ocup = board[k-1][s].ocup;
                        }
                    }
                }
            }
        }
        int row;
        int col;
        Point **board;
};

class Block{
    public:
        Block(Point op1, Point op2, Point op3, Point op4){
            for(int i = 0;i < 4;i++){
                for(int j = 0;j < 4;j++){
                    Point tmp(i + 1, j + 1, 0);
                    block_rec[i][j] = tmp; 
                }
            }
            block_rec[op1.x - 1][op1.y - 1].ocup = 1;
            block_rec[op2.x - 1][op2.y - 1].ocup = 1;
            block_rec[op3.x - 1][op3.y - 1].ocup = 1;
            block_rec[op4.x - 1][op4.y - 1].ocup = 1;  
        }
        Block(const Block &blk){
            for(int i = 0;i < 4;i++){
                for(int j = 0;j < 4;j++)
                    block_rec[i][j] = blk.block_rec[i][j];
            }
        }
        //way == 1 up or down, way == 0 left or right;
        void move(int way, int dir){
            for(int i = 0;i < 4;i++){
                for(int j = 0;j < 4;j++){
                    if(way) block_rec[i][j].x += dir;
                    else block_rec[i][j].y += dir; 
                }
            }
        }
        Point block_rec[4][4];
};

int main(){
    map<string, Block> block_map;
    Point a(3, 1) ,b(3, 2), c(3, 3) ,d(4, 2);
    Block T1(a, b, c, d);
    Point a1(3, 1), b1(2, 2), c1(3, 2), d1(4, 2);
    Block T2(a1, b1, c1, d1);
    Point a2(4, 1), b2(3, 2), c2(4, 2), d2(4, 3);
    Block T3(a2, b2, c2, d2);
    Point a3(2, 1), b3(3, 1), c3(4, 1), d3(3, 2);
    Block T4(a3, b3, c3, d3);
    Point a4(2, 1), b4(3, 1), c4(4, 1), d4(4, 2);
    Block L1(a4, b4, c4, d4);
    Point a5(3, 1), b5(3, 2), c5(3, 3), d5(4, 1);
    Block L2(a5, b5, c5, d5);
    Point a6(2, 1), b6(2, 2), c6(3, 2), d6(4, 2);
    Block L3(a6, b6, c6, d6);
    Point a7(3, 3), b7(4, 1), c7(4, 2), d7(4, 3);
    Block L4(a7, b7, c7, d7);
    Point a8(2, 2), b8(3, 2), c8(4, 1), d8(4, 2);
    Block J1(a8, b8, c8, d8);         
    Point a9(3, 1), b9(4, 3), c9(4, 1), d9(4, 2);
    Block J2(a9, b9, c9, d9);
    Point a10(2, 1), b10(2, 2), c10(3, 1), d10(4, 1);
    Block J3(a10, b10, c10, d10);
    Point a11(3, 1), b11(3, 2), c11(3, 3), d11(4, 3);
    Block J4(a11, b11, c11, d11);
    Point a12(4, 1), b12(3, 2), c12(4, 2), d12(3, 3);
    Block S1(a12, b12, c12, d12);
    Point a13(2, 1), b13(3, 1), c13(3, 2), d13(4, 2);
    Block S2(a13, b13, c13, d13);
    Point a14(3, 1), b14(3, 2), c14(4, 2), d14(4, 3);
    Block Z1(a14, b14, c14, d14);
    Point a15(2, 2), b15(3, 1), c15(3, 2), d15(4, 1);
    Block Z2(a15, b15, c15, d15);
    Point a16(1, 1), b16(2, 1), c16(3, 1), d16(4, 1);
    Block I1(a16, b16, c16, d16);
    Point a17(4, 1), b17(4, 2), c17(4, 3), d17(4, 4);
    Block I2(a17, b17, c17, d17);
    Point a18(3, 1), b18(3, 2), c18(4, 1), d18(4, 2);
    Block O(a18, b18, c18, d18);
    block_map.insert(pair<string, Block>("T1", T1));
    block_map.insert(pair<string, Block>("T2", T2));
    block_map.insert(pair<string, Block>("T3", T3));
    block_map.insert(pair<string, Block>("T4", T4));
    block_map.insert(pair<string, Block>("L1", L1));
    block_map.insert(pair<string, Block>("L2", L2));
    block_map.insert(pair<string, Block>("L3", L3));
    block_map.insert(pair<string, Block>("L4", L4));
    block_map.insert(pair<string, Block>("J1", J1));
    block_map.insert(pair<string, Block>("J2", J2));
    block_map.insert(pair<string, Block>("J3", J3));
    block_map.insert(pair<string, Block>("J4", J4));
    block_map.insert(pair<string, Block>("S1", S1));
    block_map.insert(pair<string, Block>("S2", S2));
    block_map.insert(pair<string, Block>("Z1", Z1));
    block_map.insert(pair<string, Block>("Z2", Z2));
    block_map.insert(pair<string, Block>("I1", I1));
    block_map.insert(pair<string, Block>("I2", I2));
    block_map.insert(pair<string, Block>("O", O));
    //read file
    ifstream file;
    file.open("3_revised.data");

    int row, col, ref_col, move;
    string str;
    file >> row >> col;
    Rec teris(row, col), tmp_teris(row, col);
    
    while(1){
        file >> str;
        if(str == "End") break;
        else{
            file >> ref_col >> move;
            Block cur = block_map.at(str);

            for(int i = 0;i < 4;i++){
                for(int j = 0;j < 4;j++){
                    cur.block_rec[i][j].x -= 3;
                    cur.block_rec[i][j].y += (ref_col - 1);
                }
            }
            //move
            int flag = 0, used = 0;
            while(1){
                cur.move(1, 1);
                for(int i = 3;i >= 0;i--){
                    for(int j = 0;j < 4;j++){
                        //over col
                        if(cur.block_rec[i][j].x - 1 >= teris.row){
                            if(!used) cur.move(0, move);
                            cur.move(1, -1);
                            flag = 1;  
                        }
                        //over other block
                        else if(cur.block_rec[i][j].ocup && cur.block_rec[i][j].x >= 1){
                            if(teris.board[cur.block_rec[i][j].x - 1][cur.block_rec[i][j].y - 1].ocup){
                                if(used){
                                    cur.move(1, -1);
                                    flag = 1;
                                }else{
                                    cur.move(1 ,-1);
                                    cur.move(0, move);
                                    used = 1;
                                }
                            }
                        }else 
                            continue;
                    }
                    if(flag) break; 
                }
                //hit
                if(flag){
                    for(int i = 0;i < 4;i++){
                        for(int j = 0;j < 4;j++){
                            //whether over horizontal?
                            if(cur.block_rec[i][j].ocup)
                                teris.board[cur.block_rec[i][j].x - 1][cur.block_rec[i][j].y - 1].ocup = 1;
                        }
                    }
                    teris.check_eliminate();
                    break;
                }
            }
        }
    }
    file.close();

    for(int i = 0;i < teris.row;i++){
        for(int j = 0;j < teris.col;j++){
            cout << teris.board[i][j].ocup << " ";
        }
        cout << endl;
    }
    return 0;
}