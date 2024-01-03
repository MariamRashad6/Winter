#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

// functions
void drawPenguin();
void drawFloor();
void drawWall();
void drawWindow();
void drawFirePlace();
void penguinAnimation(int);
void firePlaceAnimation(int);
void windowAnimation(int);
void drawSnow(int x,int y);
int flag=0; // flag controls animation starting at night theme

void draw_clock();
void timer(int);
void star(int);
void draw_Christmas_tree();
void draw_chair();

void init(){
    glClearColor(1,1,1,0); // background
}

// function to display shape
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // wall
    drawWall();
    // floor
    drawFloor();
    // window
    drawWindow();
    // tree
    draw_Christmas_tree();
    // fire place
    drawFirePlace();
    //draw penguin
    drawPenguin();
    // chair
    draw_chair();
    // clock
    draw_clock();
    // display frame buffer
    glFlush();
}

void reshape(int w , int h){
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-30,30,-20,20);
    glMatrixMode(GL_MODELVIEW);
}




int main(int argc , char**argv){

    glutInit(&argc,argv);
    // display mode
    glutInitDisplayMode(GLUT_RGB);

    // window
    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);
    glutCreateWindow("19101623-19103276");

    // callback function
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // functions responsible for animation
    glutTimerFunc(0,firePlaceAnimation,0);
    glutTimerFunc(0,penguinAnimation,0);
    glutTimerFunc(0,windowAnimation,0);
    glutTimerFunc(0,timer,0);
    glutTimerFunc(0,star,0);
    init();

    // loop runs till close instruction
    glutMainLoop();
}

// drawing penguin
float eyeRadius=1;
void drawPenguin(){

    // main black body
    glColor3ub(25,29,41);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5;
        glVertex2f(r*cos(angle)-3,r*sin(angle)-11);
    }
    glEnd();
    // right circle
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=4;
        glVertex2f(r*cos(angle)-1,r*sin(angle)-13.5);
    }
    glEnd();
    // left circle
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=4;
        glVertex2f(r*cos(angle)-5,r*sin(angle)-13.5);
    }
    glEnd();
    // bottom oval
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=4;
        glVertex2f(r*cos(angle)-3,r/2*sin(angle)-15.6);
    }
    glEnd();

    // white body part
    glColor3ub(234,233,231);
    // bottom oval
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=4;
        glVertex2f(r*cos(angle)-3,r/2*sin(angle)-13.8);
    }
    glEnd();
    // left oval
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=3.5;
        glVertex2f(r/2*cos(angle)-4.9,r*sin(angle)-12);
    }
    glEnd();
    // left circle
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=2.8;
        glVertex2f(r*cos(angle)-4.28,r*sin(angle)-12.9);
    }
    glEnd();
    // right circle
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=2.8;
        glVertex2f(r*cos(angle)-1.72,r*sin(angle)-12.9);
    }
    glEnd();
    // right oval
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=3.5;
        glVertex2f(r/2*cos(angle)-1.1,r*sin(angle)-12);
    }
    glEnd();

    // nose
    // shadow
    glColor3ub(237,166,95);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r*cos(angle)-3,r/3*sin(angle)-10.57);
    }
    glEnd();
    //
    glColor3ub(237,197,110);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r*cos(angle)-3,r/3*sin(angle)-10.4);
    }
    glEnd();

    // eyes
    // left eye
    glColor3ub(25,29,41);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.4;
        glVertex2f(r/1.3*cos(angle)-4.5,r/eyeRadius*sin(angle)-9.9);
    }
    glEnd();
    // right eye
    glColor3ub(25,29,41);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.4;
        glVertex2f(r/1.3*cos(angle)-1.5,r/eyeRadius*sin(angle)-9.9);
    }
    glEnd();

    // hat
    // half oval
    glColor3ub(233,95,59);
    glBegin(GL_POLYGON);
    for(float i=0 ; i<200 ;i++){
        float angle = i*3.14/180;
        float r=3.5;
        glVertex2f(r/1.2*cos(angle)-4,r/1.1*sin(angle)-6.6);
    }
    glEnd();
    // rectangle
    glColor3ub(186,58,31);
    glBegin(GL_POLYGON);
    glVertex2f(-7,-8);
    glVertex2f(-0.9,-7);
    glVertex2f(-0.9,-6);
    glVertex2f(-7,-7);
    glEnd();

    // hat ball
    glColor3ub(238,246,235);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r*cos(angle)-4.5,r*sin(angle)-3);
    }
    glEnd();
    // circles
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.3;
        glVertex2f(r*cos(angle)-4.5,r*sin(angle)-5);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.3;
        glVertex2f(r*cos(angle)-5.5,r*sin(angle)-4.5);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.3;
        glVertex2f(r*cos(angle)-2.7,r*sin(angle)-4.2);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.3;
        glVertex2f(r*cos(angle)-3,r*sin(angle)-5.3);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.3;
        glVertex2f(r*cos(angle)-5.5,r*sin(angle)-5.5);
    }
    glEnd();
    // scarf
    // rectangle
    glColor3ub(186,58,31);
    glBegin(GL_POLYGON);
    glVertex2f(-8,-11.16);
    glVertex2f(2,-11.16);
    glVertex2f(2,-12.5);
    glVertex2f(-8,-12.5);
    glEnd();
    // left oval
    glColor3ub(186,58,31);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r*cos(angle)-8,r/1.2*sin(angle)-11.56);
    }
    glEnd();
    // right oval
    glColor3ub(186,58,31);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r*cos(angle)+2,r/1.2*sin(angle)-11.56);
    }
    glEnd();

    // cup
    // half circle
    glColor3ub(236,178,176);
    glBegin(GL_POLYGON);
    for(int i=0;i<=180;i++){
        float angle = i*3.14/180;
        float r=2;
        glVertex2f(-r*cos(angle)-3,-r*sin(angle)-12.5);
    }
    glEnd();
    // half circle
    glBegin(GL_POLYGON);
    for(int i=0;i<=180;i++){
        float angle = i*3.14/180;
        float r=2;
        glVertex2f(r*cos(angle)-3,r/2*sin(angle)-12.5);
    }
    glEnd();
    // drink
    // oval
    glColor3ub(132,94,58);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1.5;
        glVertex2f(r*cos(angle)-3,r/3*sin(angle)-12.3);
    }
    glEnd();

    // hands
    // left hand
    glColor3ub(25,29,41);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=2;
        glVertex2f(r*cos(angle),r/3*sin(angle)-13.3);
    }
    glEnd();
    // right hand
    glColor3ub(25,29,41);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=2;
        glVertex2f(r*cos(angle)-6,r/3*sin(angle)-13.3);
    }
    glEnd();

    // legs
    glColor3ub(237,197,110);
    // left leg
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r/1.1*cos(angle)-4.5,r/2.2*sin(angle)-17.8);
    }
    glEnd();
    // right leg
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r/1.1*cos(angle)-1.5,r/2.2*sin(angle)-17.8);
    }
    glEnd();
}

// function to draw floor
void drawFloor(){
    glColor3ub(53,59,83);
    glBegin(GL_POLYGON);
    glVertex2f(-30,-10);
    glVertex2f(30,-10);
    glVertex2f(30,-20);
    glVertex2f(-30,-20);
    glEnd();

    glColor3ub(212, 189, 158);
    glBegin(GL_POLYGON);
    glVertex2f(-30,-9);
    glVertex2f(30,-9);
    glVertex2f(30,-10.2);
    glVertex2f(-30,-10.2);
    glEnd();

    // rug
    // shadow
    glColor3ub(39,41,59);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=9.5;
        glVertex2f(r*cos(angle)+1,r/2.5*sin(angle)-14.8);
    }
    glEnd();

    glColor3ub(49,107,74);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=9;
        glVertex2f(r*cos(angle)+1,r/2.5*sin(angle)-14.8);
    }
    glEnd();


    glColor3ub(64, 133, 93);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5;
        glVertex2f(r*cos(angle)+1,r/2.5*sin(angle)-14.8);
    }
    glEnd();

}

// function to draw wall
void drawWall(){
    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    glVertex2f(-30,-10);
    glVertex2f(30,-10);
    glVertex2f(30,25);
    glVertex2f(-30,25);
    glEnd();
}

// function to draw window
float snowTranstion=0;
int xView=90,yView=125,zView=175;// initial color of outside view of window
void drawWindow(){
    // brown frame
    glColor3ub(128,83,50);
    glBegin(GL_POLYGON);
    glVertex2f(-28,0);
    glVertex2f(-3,0);
    glVertex2f(-3,19);
    glVertex2f(-28,19);
    glEnd();

    // outside view
    glColor3ub(xView,yView,zView);
    glBegin(GL_POLYGON);
    glVertex2f(-27,1);
    glVertex2f(-4,1);
    glVertex2f(-4,18);
    glVertex2f(-27,18);
    glEnd();

    // snow
    if(flag == 1){ // condition to start snow at night
    drawSnow(25,13);
    drawSnow(21,13);
    drawSnow(17,13);
    drawSnow(13,13);
    drawSnow(9,13);

    drawSnow(26,12);
    drawSnow(22,12);
    drawSnow(18,12);
    drawSnow(14,12);
    drawSnow(10,12);

    drawSnow(26,8.5);
    drawSnow(22,8.5);
    drawSnow(18,8.5);
    drawSnow(14,8.5);
    drawSnow(10,8.5);

    drawSnow(26,5.3);
    drawSnow(22,5.3);
    drawSnow(18,5.3);
    drawSnow(14,5.3);
    drawSnow(10,5.3);

    drawSnow(26,2.3);
    drawSnow(22,2.3);
    drawSnow(18,2.3);
    drawSnow(14,2.3);
    drawSnow(10,2.3);

    drawSnow(28.5,3.3);
    drawSnow(24.5,3.3);
    drawSnow(20.5,3.3);
    drawSnow(16.5,3.3);
    drawSnow(12.5,3.3);
    }
    // continue brown frame
    glColor3ub(128,83,50);
    // vertical rectangle
    glBegin(GL_POLYGON);
    glVertex2f(-16,0);
    glVertex2f(-15,0);
    glVertex2f(-15,19);
    glVertex2f(-16,19);
    glEnd();
    // horizontal rectangle
    glBegin(GL_POLYGON);
    glVertex2f(-28,10);
    glVertex2f(-3,10);
    glVertex2f(-3,9);
    glVertex2f(-28,9);
    glEnd();
    // horizontal rectangle
    glBegin(GL_POLYGON);
    glVertex2f(-28,1);
    glVertex2f(-3,1);
    glVertex2f(-3,0);
    glVertex2f(-28,0);
    glEnd();

    // wall
    glColor3ub(216, 200, 178);
    glBegin(GL_POLYGON);
    glVertex2f(-28,0);
    glVertex2f(-3,0);
    glVertex2f(-3,-0.5);
    glVertex2f(-28,-0.5);
    glEnd();
    // curtain

    // left side
    glColor3ub(186,58,31);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=7;
        glVertex2f(-r*cos(angle)-25,-r*sin(angle)+15);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-28.5,-2.5);
    glVertex2f(-25,-2.5);
    glVertex2f(-25,19);
    glVertex2f(-28.5,19);
    glEnd();

    // right side
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=7;
        glVertex2f(-r*cos(angle)-6.5,-r*sin(angle)+15);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-3,-2.5);
    glVertex2f(-7,-2.5);
    glVertex2f(-7,19);
    glVertex2f(-3,19);
    glEnd();


    // wall
    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    glVertex2f(-28,25);
    glVertex2f(-3,25);
    glVertex2f(-3,18.8);
    glVertex2f(-28,18.8);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-30,-2.5);
    glVertex2f(-26.5,-2.5);
    glVertex2f(-26.5,20);
    glVertex2f(-30,20);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex2f(3,-2.5);
    glVertex2f(-5.4,-2.5);
    glVertex2f(-5.4,20);
    glVertex2f(3,20);
    glEnd();
}

// fire place
int x=252,y=182,z=77; // outer fire color
void drawFirePlace(){

    // wooden frame
    glColor3ub(114,68,68);
    glBegin(GL_POLYGON);
    glVertex2f(-8,5);
    glVertex2f(9,5);
    glVertex2f(9,-10);
    glVertex2f(-8,-10);
    glEnd();
    // frame decoration
    //left
    glColor3ub(88,50,50);
    glBegin(GL_POLYGON);
    glVertex2f(-8.1,1);
    glVertex2f(-6.1,1);
    glVertex2f(-6.1,0);
    glVertex2f(-8.1,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-8.1,-3);
    glVertex2f(-6.1,-3);
    glVertex2f(-6.1,-2);
    glVertex2f(-8.1,-2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-8.1,-6);
    glVertex2f(-6.1,-6);
    glVertex2f(-6.1,-5);
    glVertex2f(-8.1,-5);
    glEnd();
    //right
    glBegin(GL_POLYGON);
    glVertex2f(9.1,1);
    glVertex2f(7.1,1);
    glVertex2f(7.1,0);
    glVertex2f(9.1,0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(9.1,-3);
    glVertex2f(7.1,-3);
    glVertex2f(7.1,-2);
    glVertex2f(9.1,-2);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(9.1,-6);
    glVertex2f(7.1,-6);
    glVertex2f(7.1,-5);
    glVertex2f(9.1,-5);
    glEnd();

    // top horizontal rectangle
    glColor3ub(128,83,50);
    glBegin(GL_POLYGON);
    glVertex2f(-9,5);
    glVertex2f(10,5);
    glVertex2f(10,3.5);
    glVertex2f(-9,3.5);
    glEnd();

    // inside fire place
    glColor3ub(80,63,53);
    glBegin(GL_POLYGON);
    glVertex2f(-5,1.5);
    glVertex2f(6,1.5);
    glVertex2f(6,-8);
    glVertex2f(-5,-8);
    glEnd();
    // shadow
    // horizontal
    glColor3ub(71,56,41);
    glBegin(GL_POLYGON);
    glVertex2f(-5,1.5);
    glVertex2f(6,1.5);
    glVertex2f(6,2.5);
    glVertex2f(-5,2.5);
    glEnd();
    // vertical
    glBegin(GL_POLYGON);
    glVertex2f(5,1.5);
    glVertex2f(6,1.5);
    glVertex2f(6,-8);
    glVertex2f(5,-8);
    glEnd();
    // shadow

    // fire
    // outer circle
    if(flag == 1){
    glColor3ub(x,y,z);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=3.5;
        glVertex2f(r*cos(angle)+0.5,r*sin(angle)-5);
    }
    glEnd();
    // inner circle
    glColor3ub(244,131,53);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=2.5;
        glVertex2f(r*cos(angle)+0.5,r*sin(angle)-5.5);
    }
    glEnd();
    // ovals for fire shape
    // inner
    glColor3ub(x,y,z);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r/2*cos(angle)-1,r*sin(angle)-4);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r/2*cos(angle)+1.7,r*sin(angle)-4);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(-r*cos(angle)-0.2,-r*sin(angle)-2.9);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)-0.9,r*sin(angle)-3.4);
    }
    glEnd();
    glColor3ub(244,131,53);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+0.1,r*sin(angle)-3.53);
    }
    glEnd();
    //outer
    glColor3ub(80,63,53);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r/2*cos(angle)-1,r*sin(angle)-2.5);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=1;
        glVertex2f(r/2*cos(angle)+1.8,r*sin(angle)-2.2);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(-r*cos(angle)-0.3,-r*sin(angle)-1.9);
    }
    glEnd();
    glColor3ub(x,y,z);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.52;
        glVertex2f(r*cos(angle),r*sin(angle)-2.1);
    }
    glEnd();
    }
    // bottom horizontal rectangles
    glColor3ub(109,63,65);
    glBegin(GL_POLYGON);
    glVertex2f(-9,-8);
    glVertex2f(10,-8);
    glVertex2f(10,-10);
    glVertex2f(-9,-10);
    glEnd();

    glColor3ub(88,50,49);
    glBegin(GL_POLYGON);
    glVertex2f(-9.5,-9);
    glVertex2f(10.5,-9);
    glVertex2f(10.5,-10.5);
    glVertex2f(-9.5,-10.5);
    glEnd();
}



// function to animate fire inside fire place
void firePlaceAnimation(int){
    glutPostRedisplay();
    glutTimerFunc(10000/10,firePlaceAnimation,0); // recursion
    // flag to start fire when night theme
    if(flag == 1){
    if(x==252 && y==182 && z==77){ // change to lighter color
        x=253;
        y=205;
        z=118;
    }

    else{
        x=252;
        y=182;
        z=77;
    }
    }
}

// function to let penguin blink
void penguinAnimation(int){
    glutPostRedisplay();
    glutTimerFunc(10000/12,penguinAnimation,0); // recursion
    if(eyeRadius == 1){
        eyeRadius=5;
    }
    else{
        eyeRadius=1;
    }
}

// function to start snow fall and night
int counter=0; // counter to control start of night
void windowAnimation(int){
    glutPostRedisplay();
    glutTimerFunc(10,windowAnimation,0);

   if(snowTranstion<2){
        snowTranstion=snowTranstion+0.03;
        counter = counter+1;
    }
    else{
        snowTranstion=0;
        counter = counter+1;
    }
    if(xView==90 && yView==125 && zView==175 && counter>170){
        flag=1;
        xView=45;
        yView=57;
        zView=84;
    }

}

// function to draw snow balls in window
void drawSnow(int xs,int ys){
    glColor3ub(252,255,253);
    // circle 1
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.3;
        glVertex2f(r*cos(angle)-xs,r*sin(angle)+ys-snowTranstion);
    }
    glEnd();
    // circle 2
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.3;
        glVertex2f(r*cos(angle)-xs+0.5,r*sin(angle)+ys+1.5-snowTranstion);
    }
    glEnd();
    // circle 3
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.2;
        glVertex2f(r*cos(angle)-xs+3,r*sin(angle)+ys+2-snowTranstion);
    }
    glEnd();
    // circle 4
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.3;
        glVertex2f(r*cos(angle)-xs+3,r*sin(angle)+ys+4-snowTranstion);
    }
    glEnd();

}

// christmas tree
float xStar=255,yStar=206,zStar=125;
void draw_Christmas_tree(){

    //6th trapizium
    glColor3ub(113,139,17);
    glBegin(GL_POLYGON);
    glVertex2f(29,-9);
    glVertex2f(11,-9);
    glVertex2f(14,-5);
    glVertex2f(26,-5);
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.6;
        glVertex2f(r*cos(angle)+9,r*sin(angle)-3.7);
    }
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.6;
        glVertex2f(r*cos(angle)+31,r*sin(angle)-3.7);
    }
    glEnd();
    //the end of the 6th ones

    //5th
    glColor3ub(113,139,17);
    glBegin(GL_POLYGON);
    glVertex2f(28,-5);
    glVertex2f(12,-5);
    glVertex2f(15,-1);
    glVertex2f(25,-1);
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.6;
        glVertex2f(r*cos(angle)+9.86,r*sin(angle)+0.2);
    }
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.6;
        glVertex2f(r*cos(angle)+30.2,r*sin(angle)+0.2);
    }
    glEnd();
    // end of 5th

    //4th
    glColor3ub(113,139,17);
    glBegin(GL_POLYGON);
    glVertex2f(27-0.1,-1);
    glVertex2f(13-0.1,-1);
    glVertex2f(16-0.1,3);
    glVertex2f(24-0.1,3);
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.19;
        glVertex2f(r*cos(angle)+11.699-0.1,r*sin(angle)+3.79);
    }
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.19;
        glVertex2f(r*cos(angle)+28.699-0.1,r*sin(angle)+3.79);
    }
    glEnd();
    //end of fourth

    //third
    glColor3ub(113,139,17);
    glBegin(GL_POLYGON);
    glVertex2f(26.1,3);
    glVertex2f(14.1,3);
    glVertex2f(17.1,7);
    glVertex2f(23.1,7);
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.19;
        glVertex2f(r*cos(angle)+12.399+0.1,r*sin(angle)+7.79);
    }
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.19;
        glVertex2f(r*cos(angle)+27.699+0.1,r*sin(angle)+7.79);
    }
    glEnd();
    //end of third

    //second
    glColor3ub(113,139,17);
    glBegin(GL_POLYGON);
    glVertex2f(25+0.26,7);
    glVertex2f(15+0.26,7);
    glVertex2f(18+0.26,11);
    glVertex2f(22+0.26,11);
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.19;
        glVertex2f(r*cos(angle)+13.399+0.26,r*sin(angle)+11.79);
    }
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.19;
        glVertex2f(r*cos(angle)+26.399+0.26,r*sin(angle)+11.79);
    }
    glEnd();
    //end of second

    //first
    glColor3ub(113,139,17);
    glBegin(GL_POLYGON);
    glVertex2f(24+0.4,11);
    glVertex2f(16+0.4,11);
    glVertex2f(20+0.4,16);
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.19;
        glVertex2f(r*cos(angle)+14.699+0.4,r*sin(angle)+15.79);
    }
    glEnd();

    glColor3ub(233,215,191);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=5.19;
        glVertex2f(r*cos(angle)+24.699+0.4,r*sin(angle)+15.79);
    }
    glEnd();
    //end of first

    //shadows

    glColor3ub(73,88,4);
    glBegin(GL_POLYGON);
    glVertex2f(18.7,11);
    glVertex2f(21.5,11);
    glVertex2f(21.7, 10.4);
    glEnd();

    glColor3ub(73,88,4);
    glBegin(GL_POLYGON);
    glVertex2f(17.48,7);
    glVertex2f(22.6,7);
    glVertex2f(22.8, 6.2);
    glEnd();

    glColor3ub(73,88,4);
    glBegin(GL_POLYGON);
    glVertex2f(16.39,3);
    glVertex2f(23.5,3);
    glVertex2f(23.7,2);
    glEnd();

    glColor3ub(73,88,4);
    glBegin(GL_POLYGON);
    glVertex2f(15.1,-1);
    glVertex2f(24.68,-1);
    glVertex2f(25.1,-2.2);
    glEnd();

    glColor3ub(73,88,4);
    glBegin(GL_POLYGON);
    glVertex2f(14.2,-5);
    glVertex2f(25.68,-5);
    glVertex2f(26.1,-6.4);
    glEnd();


    //balls
    //a7mar
    glColor3ub(186,41,12);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+18.9,r*sin(angle)+12.4);
    }
    glEnd();

    //pink
    glColor3ub(191,58,125);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+18.2,r*sin(angle)+8.9);
    }
    glEnd();

    //purple
    glColor3ub(69,45,115);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+21.7,r*sin(angle)+11.4);
    }
    glEnd();

    //yellow
    glColor3ub(244,164,68);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+22.2,r*sin(angle)+6.6);
    }
    glEnd();

    //pink
    glColor3ub(191,58,125);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+17,r*sin(angle)+4.8);
    }
    glEnd();

    //yellow
    glColor3ub(69,45,115);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+24.8,r*sin(angle)+3.4);
    }
    glEnd();

    //a7mar
    glColor3ub(186,41,12);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+19.8,r*sin(angle)+2.5);
    }
    glEnd();

    //purple
    glColor3ub(69,45,115);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+16.4,r*sin(angle)+1);
    }
    glEnd();

    //pink
    glColor3ub(191,58,125);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+24.5,r*sin(angle)+0);
    }
    glEnd();

    //yellow
    glColor3ub(244,164,68);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+20.5,r*sin(angle)+-2.5);
    }
    glEnd();

    //a7mar
    glColor3ub(186,41,12);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+14.5,r*sin(angle)+-3.6);
    }
    glEnd();

    //purple
    glColor3ub(69,45,115);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+25.5,r*sin(angle)+-3.7);
    }
    glEnd();

    //pink
    glColor3ub(191,58,125);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+23.5,r*sin(angle)+-6);
    }
    glEnd();


    //yellow
    glColor3ub(244,164,68);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+14,r*sin(angle)+-6.6);
    }
    glEnd();


    //a7mar
    glColor3ub(186,41,12);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.5;
        glVertex2f(r*cos(angle)+19.3,r*sin(angle)+-8.4);
    }
    glEnd();




    //small balls

    // red
    glColor3ub(255,158,128);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+18.74,r*sin(angle)+12.6);
    }
    glEnd();

    // pink
    glColor3ub(247,140,189);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+18.04,r*sin(angle)+9.1);
    }
    glEnd();

    // purple
    glColor3ub(166,150,181);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+21.54,r*sin(angle)+11.6);
    }
    glEnd();

    // yellow
    glColor3ub(255,205,160);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+22.04,r*sin(angle)+6.8);
    }
    glEnd();

    //pink
    glColor3ub(247,140,189);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+16.84,r*sin(angle)+5);
    }
    glEnd();

    // purple
    glColor3ub(166,150,181);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+24.64,r*sin(angle)+3.6);
    }
    glEnd();

    //a7mar
    glColor3ub(255,158,128);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+19.64,r*sin(angle)+2.7);
    }
    glEnd();

    //purple
    glColor3ub(166,150,181);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+16.24,r*sin(angle)+1.2);
    }
    glEnd();

    //pink
    glColor3ub(247,140,189);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+24.34,r*sin(angle)+0.2);
    }
    glEnd();

    //yellow
    glColor3ub(255,205,160);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+20.34,r*sin(angle)+-2.3);
    }
    glEnd();

    //a7mar
    glColor3ub(255,158,128);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+14.34,r*sin(angle)+-3.4);
    }
    glEnd();

    //purple
    glColor3ub(166,150,181);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+25.34,r*sin(angle)+-3.5);
    }
    glEnd();

    //pink
    glColor3ub(247,140,189);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+23.34,r*sin(angle)+-5.8);
    }
    glEnd();


    //yellow
    glColor3ub(255,205,160);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+13.84,r*sin(angle)+-6.4);
    }
    glEnd();


    //a7mar
    glColor3ub(255,158,128);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.19;
        glVertex2f(r*cos(angle)+19.14,r*sin(angle)+-8.2);
    }
    glEnd();


    //presents

    // pink
    // box
    glColor3ub(200,52,119);
    glBegin(GL_POLYGON);
    glVertex2f(11, -9.5);
    glVertex2f(17, -9.5);
    glVertex2f(17,-12.5);
    glVertex2f(11,-12.5);
    glEnd();
    // cover
    glColor3ub(149,39,89);
    glBegin(GL_POLYGON);
    glVertex2f(10.5, -9.5);
    glVertex2f(17.5, -9.5);
    glVertex2f(17.5,-7.5);
    glVertex2f(10.5,-7.5);
    glEnd();
    // ribbon
    glColor3ub(220,212,227);
    glBegin(GL_POLYGON);
    glVertex2f(13.5, -9.5);
    glVertex2f(14.5, -9.5);
    glVertex2f(14.5,-12.47);
    glVertex2f(13.5,-12.47);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(12.09+0.5,-6.5);
    glVertex2f(12.09+0.5,-8.5);
    glVertex2f(13.49+0.5,-7.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(15.1+0.5,-6.5);
    glVertex2f(15.1+0.5,-8.5);
    glVertex2f(13.49+0.5,-7.5);
    glEnd();

    glColor3ub(195,189,203);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.4;
        glVertex2f(r*cos(angle)+14.12,r*sin(angle)-7.5);
    }
    glEnd();

    // purple
    // box
    glColor3ub(131,118,228);
    glBegin(GL_POLYGON);
    glVertex2f(22,-9.5);
    glVertex2f(27,-9.5);
    glVertex2f(27,-12.5);
    glVertex2f(22,-12.5);
    glEnd();
    // cover
    glColor3ub(98,88,169);
    glBegin(GL_POLYGON);
    glVertex2f(20.5, -9.5);
    glVertex2f(27.5, -9.5);
    glVertex2f(27.5,-7.5);
    glVertex2f(20.5,-7.5);
    glEnd();
    // ribbon
    glColor3ub(220,212,227);
    glBegin(GL_POLYGON);
    glVertex2f(23.5, -9.5);
    glVertex2f(24.5, -9.5);
    glVertex2f(24.5,-12.47);
    glVertex2f(23.5,-12.47);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(22.09+0.5,-6.5);
    glVertex2f(22.09+0.5,-8.5);
    glVertex2f(23.49+0.5,-7.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(25.1+0.5,-6.5);
    glVertex2f(25.1+0.5,-8.5);
    glVertex2f(23.49+0.5,-7.5);
    glEnd();

    glColor3ub(195,189,203);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.4;
        glVertex2f(r*cos(angle)+24.12,r*sin(angle)-7.5);
    }
    glEnd();

    // orange
    // box
    glColor3ub(246,109,60);
    glBegin(GL_POLYGON);
    glVertex2f(16,-10.5);
    glVertex2f(22,-10.5);
    glVertex2f(22,-15.5);
    glVertex2f(16,-15.5);
    glEnd();
    // cover
    glColor3ub(187,81,44);
    glBegin(GL_POLYGON);
    glVertex2f(15.5, -10.5);
    glVertex2f(22.5, -10.5);
    glVertex2f(22.5,-8.5);
    glVertex2f(15.5,-8.5);
    glEnd();
    // ribbon
    glColor3ub(220,212,227);
    glBegin(GL_POLYGON);
    glVertex2f(18.5, -10.5);
    glVertex2f(19.5, -10.5);
    glVertex2f(19.5,-15.47);
    glVertex2f(18.5,-15.47);
    glEnd();


    glBegin(GL_TRIANGLES);
    glVertex2f(17.09+0.5,-7.5);
    glVertex2f(17.09+0.5,-9.5);
    glVertex2f(18.49+0.5,-8.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(20.1+0.5,-7.5);
    glVertex2f(20.1+0.5,-9.5);
    glVertex2f(18.49+0.5,-8.5);
    glEnd();

    glColor3ub(195,189,203);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.4;
        glVertex2f(r*cos(angle)+19.12,r*sin(angle)-8.5);
    }
    glEnd();

    // star
    glColor3ub(xStar,yStar,zStar);
    glBegin(GL_POLYGON);
    glVertex2f(3.5+17,3+12);
    glVertex2f(4.5+17,2.5+12);
    glVertex2f(3.5+17,1.7+12);
    glVertex2f(4+17,1+12);
    glVertex2f(3+17,1.5+12);
    glVertex2f(2+17,1+12);
    glVertex2f(2.1+17,1.7+12);
    glVertex2f(1.5+17,2.5+12);
    glVertex2f(2.8+17,3.1+12);
    glVertex2f(2.3+17,2.8+12);
    glVertex2f(3+17,4+12);
    glEnd();


}

float step=0;
void draw_clock(){
    glColor3ub(125,54,34);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=4;
        glVertex2f(r*cos(angle)+3,r*sin(angle)+15);
    }
    glEnd();


    glColor3ub(234, 182, 118);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=3.5;
        glVertex2f(r*cos(angle)+3,r*sin(angle)+15);
    }
    glEnd();


    glColor3ub(125,54,34);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
        float angle = i*3.14/180;
        float r=0.2;
        glVertex2f(r*cos(angle)+3,r*sin(angle)+15);
    }
    glEnd();

    // clock arrow and rotation
    glPushMatrix();
    glColor3ub(125,54,34);
    glLineWidth(1.5);

    glLoadIdentity();
    glTranslatef(3,15,0);
    glRotatef(45-step,0,0,1);
    glTranslatef(-3,-15,0);

    glBegin(GL_LINES);
    glVertex2f(3, 15);
    glVertex2f(3, 13);
    glEnd();
    glPopMatrix();


    glColor3ub(125,54,34);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(3, 12.5);
    glVertex2f(3, 12);


    glEnd();


    glColor3ub(125,54,34);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(3, 18);
    glVertex2f(3, 17.5);


    glEnd();


    glColor3ub(125,54,34);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(6, 15);
    glVertex2f(5.5, 15);


    glEnd();


    glColor3ub(125,54,34);
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2f(0.5, 15);
    glVertex2f(0, 15);


    glEnd();
}

// clock animation
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000,timer,0); // recursion
    step=step+40;
}

// star animation
void star(int){
    glutPostRedisplay();
    glutTimerFunc(10000/10,star,0); // recursion

    if(xStar==255 && yStar==206 && zStar==125){
        xStar=244;
        yStar=164;
        zStar=68;
    }

    else{
        xStar=255;
        yStar=206;
        zStar=125;
    }

}

// function to draw chair
void draw_chair(){
    glColor3ub(190,103,49);
    glBegin(GL_POLYGON);
    glVertex2f(-27, -1.7);
    glVertex2f(-17, -1.7);
    glVertex2f(-17, -11);
    glVertex2f(-27, -11);
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    glVertex2f(-28.9,-2.9);
    glVertex2f(-25.9,-2.9);
    glVertex2f(-25.9,-9);
    glVertex2f(-28.9,-9);
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=1.5;
       glVertex2f(r*cos(angle)+-27.38,r*sin(angle)+-3.2);
    }
    glEnd();

    glColor3ub(190,103,49);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=1;
       glVertex2f(r*cos(angle)+-17.5,r*sin(angle)+-2.65);
    }
    glEnd();

    glColor3ub(190,103,49);
    glBegin(GL_POLYGON);
    glVertex2f(-16.6, -2);
    glVertex2f(-17, -2);
    glVertex2f(-17, -11);
    glVertex2f(-16.6, -11);
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-24,r*sin(angle)+-5);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-22,r*sin(angle)+-5);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-20,r*sin(angle)+-5);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-24,r*sin(angle)+-6.5);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-22,r*sin(angle)+-6.5);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-20,r*sin(angle)+-6.5);
    }
    glEnd();


    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);

    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-24,r*sin(angle)+-8);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-22,r*sin(angle)+-8);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=0.3;
       glVertex2f(r*cos(angle)+-20,r*sin(angle)+-8);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    glVertex2f(-16.7,-8);
    glVertex2f(-12,-8);
    glVertex2f(-12,-11);
    glVertex2f(-16.7,-11);
    glEnd();

    glColor3ub(190,103,49);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=1.5;
       glVertex2f(r*cos(angle)+-12,r*sin(angle)+-9.5);
    }
    glEnd();

    glColor3ub(181,82,25);
    glBegin(GL_POLYGON);
    glVertex2f(-25.9,-9);
    glVertex2f(-12,-9);
    glVertex2f(-12,-11);
    glVertex2f(-25.9,-11);
    glEnd();

    glColor3ub(181,82,25);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=1;
       glVertex2f(r*cos(angle)+-12.27,r*sin(angle)+-9.99);
    }
    glEnd();

    glColor3ub(190,103,49);
    glBegin(GL_POLYGON);
    glVertex2f(-28.9,-8);
    glVertex2f(-22,-8);
    glVertex2f(-22,-11);
    glVertex2f(-28.9,-11);
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<=360;i++){
       float angle = i*3.14/180;
       float r=1.5;
       glVertex2f(r*cos(angle)+-22,r*sin(angle)+-9.5);
    }
    glEnd();

    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    glVertex2f(-28.9,-11);
    glVertex2f(-23,-11);
    glVertex2f(-23,-15);
    glVertex2f(-28.9,-15);
    glEnd();


    glColor3ub(190,103,49);
    glBegin(GL_POLYGON);
    glVertex2f(-12,-11);
    glVertex2f(-23,-11);
    glVertex2f(-23,-15);
    glVertex2f(-12,-15);
    glEnd();


    glColor3ub(141,42,0);
    glBegin(GL_POLYGON);
    glVertex2f(-14,-12);
    glVertex2f(-21,-12);
    glVertex2f(-21,-14);
    glVertex2f(-14,-14);
    glEnd();

    glColor3ub(113, 62, 29);
    glBegin(GL_POLYGON);
    glVertex2f(-28.9,-11);
    glVertex2f(-23,-11);
    //glVertex2f(-23,-12);
    glVertex2f(-28.9,-12);
    glEnd();


}
