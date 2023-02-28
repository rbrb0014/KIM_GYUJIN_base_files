module num_7seg_B(out,w,x,y,z);
/*
    about Fb();
    0000 1
    0001 0
    0010 0
    0011 0
    0100 1
    0101 1
    0110 1
    0111 0
    1000 1
    1001 1
*/
input w,x,y,z;
output out;

wire w,x,y,z,out;

//assign out=(~y & (x|~z))|(x&~z)|w;
assign out=(x&(y^z))|w|~(y|z);

endmodule