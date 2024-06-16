#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>

#define VERSION "1.0.1"

void print_usage(const char *program_name) {
    printf("Usage: %s <file.yaml> <key>\n", program_name);
    printf("       %s -h | --help\n", program_name);
}

void print_version_short() {
    printf("%s\n", VERSION);
}

void print_version_long() {
    printf("pyaml version %s\n", VERSION);
}

void print_help(const char *program_name) {
    printf("Usage: %s <file.yaml> <key>\n", program_name);
    printf("       %s -h | --help\n", program_name);
    printf("\n");
    printf("Options:\n");
    printf("  -v, --version   Show the program version\n");
    printf("  -h, --help      Show this help message\n");
    printf("\n");
    printf("Examples:\n");
    printf("  %s config.yml program.name\n", program_name);
    printf("  %s -v\n", program_name);
    printf("  %s --version\n", program_name);
    printf("  %s -h\n", program_name);
    printf("  %s --help\n", program_name);
    printf("\n");
    printf("To integrate with a Bash script:\n");
    printf("  server_port=$(%s config.yml server.port)\n", program_name);
    printf("  echo $server_port\n");
    printf("\n");
    printf("To pipe the output to another program:\n");
    printf("  %s config.yml program.name | another_program\n", program_name);
    printf("\n");
    printf("Note:\n");
    printf("  When specifying <key>, use dot notation for nested keys.\n");
    printf("  Please note that the spelling is case-sensitive!\n");
    printf("  For example, to access 'build.version' in the YAML file:\n");
    printf("    %s test.yml program.build.version\n", program_name);
}

void parse_yaml(const char *filename, const char *key) {
    FILE *fh = fopen(filename, "r");
    if (!fh) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    yaml_parser_t parser;
    yaml_document_t doc;

    if (!yaml_parser_initialize(&parser)) {
        fputs("Failed to initialize parser!\n", stderr);
        fclose(fh);
        exit(EXIT_FAILURE);
    }

    yaml_parser_set_input_file(&parser, fh);

    if (!yaml_parser_load(&parser, &doc)) {
        fprintf(stderr, "Failed to load YAML document: %s\n", parser.problem);
        yaml_parser_delete(&parser);
        fclose(fh);
        exit(EXIT_FAILURE);
    }

    yaml_node_t *root = yaml_document_get_root_node(&doc);
    if (!root) {
        fprintf(stderr, "Error: YAML document is empty.\n");
        yaml_parser_delete(&parser);
        yaml_document_delete(&doc);
        fclose(fh);
        exit(EXIT_FAILURE);
    }

    yaml_node_t *node = root;
    char *key_token;
    char *key_copy = strdup(key); // Make a copy of key because strtok modifies the string
    key_token = strtok(key_copy, ".");
    while (key_token != NULL) {
        if (node->type != YAML_MAPPING_NODE) {
            fprintf(stderr, "Error: Invalid YAML structure.\n");
            yaml_parser_delete(&parser);
            yaml_document_delete(&doc);
            fclose(fh);
            exit(EXIT_FAILURE);
        }

        yaml_node_pair_t *pair = node->data.mapping.pairs.start;
        int found = 0;
        while (pair < node->data.mapping.pairs.top) {
            yaml_node_t *key_node = yaml_document_get_node(&doc, pair->key);
            if (key_node && key_node->type == YAML_SCALAR_NODE && strcmp((char *)key_node->data.scalar.value, key_token) == 0) {
                node = yaml_document_get_node(&doc, pair->value);
                found = 1;
                break;
            }
            pair++;
        }

        if (!found) {
            fprintf(stderr, "Error: Key '%s' not found in YAML document.\n", key);
            yaml_parser_delete(&parser);
            yaml_document_delete(&doc);
            fclose(fh);
            exit(EXIT_FAILURE);
        }

        key_token = strtok(NULL, ".");
    }

    if (node->type == YAML_SCALAR_NODE) {
        printf("%s\n", node->data.scalar.value);
    } else {
        fprintf(stderr, "Error: Key '%s' does not point to a scalar value in YAML document.\n", key);
        yaml_parser_delete(&parser);
        yaml_document_delete(&doc);
        fclose(fh);
        exit(EXIT_FAILURE);
    }

    yaml_parser_delete(&parser);
    yaml_document_delete(&doc);
    fclose(fh);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
        if (argc > 2) {
            print_usage(argv[0]);
            return EXIT_FAILURE;
        }
        if (strcmp(argv[1], "-v") == 0) {
            print_version_short();
        } else {
            print_version_long();
        }
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help(argv[0]);
        return EXIT_SUCCESS;
    }

    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    const char *key = argv[2];

    parse_yaml(filename, key);

    return EXIT_SUCCESS;
}
