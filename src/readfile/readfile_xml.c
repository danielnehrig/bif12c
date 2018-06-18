/**
 * section: Parsing
 * synopsis: Parse an XML file to a tree save it into a struct and output struct and free it
 * purpose: Demonstrate the use of xmlReadFile() to read an XML file
 *          into a tree and and xmlFreeDoc() to free the resulting tree
 */

#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

struct Person {
  char *familyName;
  char *firstName;
} Person, *myPerson;

/**
 * @filename: a filename or an URL
 *
 * Parse the resource and free the resulting tree
 */
static void readFile(const char *filename) {
    xmlDocPtr doc; /* the resulting document tree */

    doc = xmlReadFile(filename, NULL, 0);
    if (doc == NULL) {
        fprintf(stderr, "Failed to parse %s\n", filename);
        return;
    }

    xmlFreeDoc(doc);
}

int main(int argc, char **argv) {
    /*
     * this initialize the library and check potential ABI mismatches
     * between the version it was compiled for and the actual shared
     * library used.
     */
    LIBXML_TEST_VERSION

    readFile("test.xml");

    // Cleanup function for the XML library.
    xmlCleanupParser();

    // this is to debug memory for regression tests
    xmlMemoryDump();

    printf("Exit Success\n");
    return EXIT_SUCCESS;
}
