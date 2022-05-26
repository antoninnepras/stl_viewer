#include "src/mesh.h"

#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>


Mesh* mesh;
float persp = 100;
float k = -5;

void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);  // To operate on model-view matrix


  // draw mesh triangles
  for (int i = 0; i < mesh->triangle_cnt; ++i) {
    glBegin(GL_TRIANGLES);
    for (int j = 0; j < 3; ++j) {
      glColor3f(1, 1, 1);
      glVertex3f(mesh->triangles[i].vertices[j].x,
                 mesh->triangles[i].vertices[j].y,
                 mesh->triangles[i].vertices[j].z);
    }
    glEnd();

  }
  glEnable(GL_BLEND);


  glBegin(GL_LINES);
  for (int i = 0; i < mesh->triangle_cnt; ++i) {
    for (int j = 0; j < 3; ++j) {
      glColor3f(0.5, 0.5, 0.5);
      glVertex3f(mesh->triangles[i].vertices[j].x,
                 mesh->triangles[i].vertices[j].y,
                 mesh->triangles[i].vertices[j].z);
      glVertex3f(mesh->triangles[i].vertices[(j + 1) % 3].x,
                 mesh->triangles[i].vertices[(j + 1) % 3].y,
                 mesh->triangles[i].vertices[(j + 1) % 3].z);
    }
  }
  glEnd();


       

  glutSwapBuffers();  // Required to copy color buffer onto the screen.
}


void reshape(int w, int h)
{
  glViewport(0, 0, w, h);


  // Set the aspect ratio of the clipping volume to match the viewport
  glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
  glLoadIdentity();             // Reset
  // Enable perspective projection with fovy, aspect, zNear and zFar
  gluPerspective(45.0f, (double)w / (double)h, 0.1f, 100);
}


void mouse_wheel(int wheel, int direction, int x, int y)
{
  display();
}


void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
    case 'w':
      glTranslatef(0.1, 0, 0);
      break;

    case 's':
      glTranslatef(-0.1, 0, 0);
      break;

    case 'a':
      glTranslatef(0, 0.1, 0);
      break;

    case 'd':
      glTranslatef(0, -0.1, 0);
      break;

    case 'e':
      glTranslatef(0, 0, 0.1);
      break;

    case 'q':
      glTranslatef(0, 0, -0.1);
      break;

    default:
      break;
  }

  display();
}


int main(int argc, char** argv)
{  // Initialize GLUT and
  mesh = mesh_load_stl_bin("stl2.stl");
  printf("%i\n", mesh->triangle_cnt);
  for (int i = 0; i < mesh->triangle_cnt; ++i) {
    printf("%lf %lf %lf\n", mesh->triangles[i].vertices[0].x,
           mesh->triangles[i].vertices[0].y, mesh->triangles[i].vertices[0].z);
  }
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100); 
  glutCreateWindow("Test window");
  glutDisplayFunc(display);
  glutMouseWheelFunc(mouse_wheel);
  glutSetCursor(GLUT_CURSOR_CROSSHAIR);
  glutKeyboardFunc(keyboard);


  glTranslatef(0, 0, k);
  glRotatef(30, 1, 1, 0);

  glutMainLoop();
  
  mesh_destroy(mesh);
  return 0;
}
