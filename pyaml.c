#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>

// Function to parse YAML and find the value for the given key
void parse_yaml_file(const char *filename, const char *key) {
    FILE *fh = fopen(filename, "r");
    if (fh == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return;
    }

    yaml_parser_t parser;
    yaml_token_t token;

    // Initialize parser
    if (!yaml_parser_initialize(&parser)) {
        fprintf(stderr, "Failed to initialize parser\n");
        fclose(fh);
        return;
    }

    // Set input file
    yaml_parser_set_input_file(&parser, fh);

    int found_key = 0;
    while (1) {
        yaml_parser_scan(&parser, &token);

        if (token.type == YAML_NO_TOKEN) {
            break;
        }

        if (token.type == YAML_KEY_TOKEN) {
            yaml_parser_scan(&parser, &token);
            if (token.type == YAML_SCALAR_TOKEN && strcmp((char *)token.data.scalar.value, key) == 0) {
                found_key = 1;
            }
        }

        if (found_key && token.type == YAML_VALUE_TOKEN) {
            yaml_parser_scan(&parser, &token);
            if (token.type == YAML_SCALAR_TOKEN) {
                printf("%s\n", token.data.scalar.value);
                found_key = 0; // Reset for next key-value pair
            }
        }

        yaml_token_delete(&token);
    }

    // Cleanup parser and close file
    yaml_parser_delete(&parser);
    fclose(fh);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file.yaml> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *key = argv[2];

    parse_yaml_file(filename, key);

    return EXIT_SUCCESS;
}
