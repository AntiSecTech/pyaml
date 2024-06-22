#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <yaml.h>
#include <unistd.h>

#define CONFIG_FILE "config.yml"

void print_usage(const char *program_name) {
    printf("Usage: %s <file.yaml> [<key>] | [ -h | --help ] | [ -v | --version ]\n", program_name);
}

void print_help(const char *program_name) {
    printf("Usage: %s <file.yaml> [key]\n", program_name);
    printf("\n");
    printf("Options:\n");
    printf("  -v, --version   Show the program version\n");
    printf("  -h, --help      Show this help message\n");
    printf("\n");
    printf("Examples:\n");
    printf("  %s file.yml\n", program_name);
	printf("  %s file.yml keyword\n", program_name);
    printf("\n");
    printf("To integrate with a Bash script:\n");
    printf("  server_port=$(%s config.yml server.port)\n", program_name);
    printf("  echo $server_port\n");
    printf("\n");
    printf("To pipe the output to another program:\n");
    printf("  %s config.yml mainkey.subkey.nestedkey | another_program\n", program_name);
    printf("\n");
    printf("Note:\n");
    printf("  When specifying [key], use dot notation for nested keys.\n");
    printf("  Please note that the spelling is case-sensitive!\n");
    printf("  For example, to access 'Version' in the YAML file:\n");
    printf("    %s config.yml build.version\n", program_name);
    printf("  If you do not specify [key], only the file content of [file.yaml] will be output.\n");
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

void highlight_yaml(const char *filename) {
    char command[256];
    snprintf(command, sizeof(command), "pygmentize -l yaml %s | less -R", filename);
    system(command);
}

void print_yaml_version_short(const char *filename) {
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
    char *keys[] = {"build", "version"};
    size_t key_count = sizeof(keys) / sizeof(keys[0]);

    for (size_t i = 0; i < key_count; ++i) {
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
            if (key_node && key_node->type == YAML_SCALAR_NODE && strcmp((char *)key_node->data.scalar.value, keys[i]) == 0) {
                node = yaml_document_get_node(&doc, pair->value);
                found = 1;
                break;
            }
            pair++;
        }

        if (!found) {
            fprintf(stderr, "Error: Key '%s' not found in YAML document.\n", keys[i]);
            yaml_parser_delete(&parser);
            yaml_document_delete(&doc);
            fclose(fh);
            exit(EXIT_FAILURE);
        }
    }

    if (node->type == YAML_SCALAR_NODE) {
        printf("%s\n", node->data.scalar.value);
    } else {
        fprintf(stderr, "Error: 'build.version' does not point to a scalar value in YAML document.\n");
    }

    yaml_parser_delete(&parser);
    yaml_document_delete(&doc);
    fclose(fh);
}

void print_yaml_version_long(const char *filename) {
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
    char *name_keys[] = {"name"};
    char *version_keys[] = {"build", "version"};
    char *release_keys[] = {"build", "release"};
    size_t name_key_count = sizeof(name_keys) / sizeof(name_keys[0]);
    size_t version_key_count = sizeof(version_keys) / sizeof(version_keys[0]);
    size_t release_key_count = sizeof(release_keys) / sizeof(release_keys[0]);

    char *name = NULL;
    char *version = NULL;
    char *release = NULL;

    // Retrieve the name
    for (size_t i = 0; i < name_key_count; ++i) {
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
            if (key_node && key_node->type == YAML_SCALAR_NODE && strcmp((char *)key_node->data.scalar.value, name_keys[i]) == 0) {
                node = yaml_document_get_node(&doc, pair->value);
                found = 1;
                break;
            }
            pair++;
        }

        if (!found) {
            fprintf(stderr, "Error: Key '%s' not found in YAML document.\n", name_keys[i]);
            yaml_parser_delete(&parser);
            yaml_document_delete(&doc);
            fclose(fh);
            exit(EXIT_FAILURE);
        }
    }

    if (node->type == YAML_SCALAR_NODE) {
        name = (char *)node->data.scalar.value;
    } else {
        fprintf(stderr, "Error: 'name' does not point to a scalar value in YAML document.\n");
    }

    node = root;
    // Retrieve the version
    for (size_t i = 0; i < version_key_count; ++i) {
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
            if (key_node && key_node->type == YAML_SCALAR_NODE && strcmp((char *)key_node->data.scalar.value, version_keys[i]) == 0) {
                node = yaml_document_get_node(&doc, pair->value);
                found = 1;
                break;
            }
            pair++;
        }

        if (!found) {
            fprintf(stderr, "Error: Key '%s' not found in YAML document.\n", version_keys[i]);
            yaml_parser_delete(&parser);
            yaml_document_delete(&doc);
            fclose(fh);
            exit(EXIT_FAILURE);
        }
    }

    if (node->type == YAML_SCALAR_NODE) {
        version = (char *)node->data.scalar.value;
    } else {
        fprintf(stderr, "Error: 'build.version' does not point to a scalar value in YAML document.\n");
    }

    node = root;
    // Retrieve the release
    for (size_t i = 0; i < release_key_count; ++i) {
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
            if (key_node && key_node->type == YAML_SCALAR_NODE && strcmp((char *)key_node->data.scalar.value, release_keys[i]) == 0) {
                node = yaml_document_get_node(&doc, pair->value);
                found = 1;
                break;
            }
            pair++;
        }

        if (!found) {
            fprintf(stderr, "Error: Key '%s' not found in YAML document.\n", release_keys[i]);
            yaml_parser_delete(&parser);
            yaml_document_delete(&doc);
            fclose(fh);
            exit(EXIT_FAILURE);
        }
    }

    if (node->type == YAML_SCALAR_NODE) {
        release = (char *)node->data.scalar.value;
    } else {
        fprintf(stderr, "Error: 'build.release' does not point to a scalar value in YAML document.\n");
    }

    if (name && version && release) {
        printf("%s version %s - %s\n", name, version, release);
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
            print_yaml_version_short(CONFIG_FILE);
        } else {
            print_yaml_version_long(CONFIG_FILE);
        }
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        print_help(argv[0]);
        return EXIT_SUCCESS;
    }

    const char *filename = argv[1];
    if (argc == 2) {
        highlight_yaml(filename);
        return EXIT_SUCCESS;
    }

    const char *key = argv[2];
    parse_yaml(filename, key);

    return EXIT_SUCCESS;
}
