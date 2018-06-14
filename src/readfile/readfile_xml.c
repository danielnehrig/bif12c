#include <mxml.h>

int main() {
  FILE *fp;
  mxml_node_t *tree;

  fp = fopen("bla.xml", "r");
  tree = mxmlLoadFile(NULL, fp, MXML_NO_CALLBACK);
  fclose(fp);
  return EXIT_SUCCESS;
}
