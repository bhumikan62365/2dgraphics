#include<stdio.h>
#define rows 30
#define columns 30
char canvas[rows][columns];
void initializeCanvas() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            canvas[i][j] = '_';
        }
    }
}
void displayCanvas() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%c ", canvas[i][j]);
        }
        printf("\n");
    }
}
void drawRectangle(int row,int col,int height,int width){
    for(int i=col;i<col+width;i++){
        canvas[row][i]='*';
        canvas[row+height-1][i]='*';
    }
    for(int i=row;i<row+height;i++){
        canvas[i][col]='*';
        canvas[i][col+width-1]='*';
    }
}
void drawLine(int row1,int col1,int row2,int col2){
    int i,start,end;
    if(row1==row2){
        if(col1<col2){
            start=col1;
            end=col2;
        }
        else{
            start=col2;
            end=col1;
        }
        for(i=start;i<=end;i++){
            canvas[row1][i]='*';
        }
    }
    else if(col1==col2){
        if(row1<row2){
            start=row1;
            end=row2;
        }
        else{
            start=row2;
            end=row1;
        }
        for(i=start;i<=end;i++){
            canvas[i][col1]='*';
        }
    }
}
void drawTriangle(int row,int col,int height){
    for(int i=0;i<height;i++){
        canvas[row+i][col-i]='*';
        canvas[row+i][col+i]='*';
    }
    for(int i=col-height+1;i<=col+height-1;i++){
        canvas[row+height-1][i]='*';
    }
}
void drawCircle(int xc,int yc,int r){
    int x,y,d;
    for(y=0;y<rows;y++){
        for(x=0;x<columns;x++){
            d=(x-xc)*(x-xc)+(y-yc)*(y-yc);
            if(d<=r*r){
                canvas[y][x]='*';
            }
        }
    }   

}
void deletArea(int row,int col,int height,int width){
    for(int i=row;i<row+height;i++){
        for(int j=col;j<col+width;j++){
            canvas[i][j]='_';
        }
    }
}
void deleteCircle(int xc,int yc,int r){
    int x,y;
    for(y=0;y<rows;y++){
        for(x=0;x<columns;x++){
            if((x-xc)*(x-xc)+(y-yc)*(y-yc)<=r*r){
                canvas[y][x]='_';
            }
        }
    }   

}
void modifyRectangle(int oldrow,int oldcol,int oldheight,int oldwidth,int newrow,int newcol,int newheight,int newwidth){
    deletArea(oldrow,oldcol,oldheight,oldwidth);
    drawRectangle(newrow,newcol,newheight,newwidth);
}
void modifyCircle(int oldxc,int oldyc,int oldr,int newxc,int newyc,int newr){
    deleteCircle(oldxc,oldyc,oldr);
    drawCircle(newxc,newyc,newr);
}
void modifyLine(int oldrow1,int oldcol1,int oldrow2,int oldcol2,int newrow1,int newcol1,int newrow2,int newcol2){
    if(oldrow1!=oldrow2 && oldcol1!=oldcol2){
        printf("Only horizontal and vertical lines can be modified.\n");
        return;
    }

int minrow, maxrow, mincol, maxcol;
if(oldrow1<oldrow2){
    minrow=oldrow1;
    maxrow=oldrow2;
}
else{
    minrow=oldrow2;
    maxrow=oldrow1;
}
if(oldcol1<oldcol2){
    mincol=oldcol1;
    maxcol=oldcol2;
}
else{
    mincol=oldcol2;
    maxcol=oldcol1;
}
    deletArea(minrow,mincol,maxrow-minrow+1,maxcol-mincol+1);
    drawLine(newrow1,newcol1,newrow2,newcol2);
}