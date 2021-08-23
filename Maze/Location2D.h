struct Location2D{
    int row; //행
    int col; //열
    //생성자 디폴트 매개변수사용, 좌표 객체 초기화
    Location2D ( int r=0, int c=0){ row = r; col = c;} 
    //자신의 이웃인지 검사
    bool isNeighbor( Location2D &p){
        return( ( row ==p.row && (col == p.col-1 || col == p.col+1))
        || (col == p.col &&( row == p.row-1 || row == p.row+1)));

    }
    //연산자 오버로딩 위치 p가 자신과 같은 위치인지 파악
    bool operator==( Location2D &p){ return row == p.row && col == p.col ;}
};