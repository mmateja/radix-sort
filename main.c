#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "radix.h"

void print(char **input, long input_size) {
	for (long i = 0; i < input_size; i++) {
		printf("%s\n", input[i]);
	}
}

void generate_data(char ***input, long n) {
	srand(time(NULL));

	*input = malloc(n * sizeof(char**));
	if (*input == NULL) {
		fprintf(stderr, "Allocation error!\n");
		exit(-1);
	}

	for (long i = 0; i < n; i++) {
		int length = 5 + rand()%6;
		(*input)[i] = malloc(length * sizeof(char));
		if ((*input)[i] == NULL) {
			fprintf(stderr, "Allocation error!\n");
			exit(-1);
		}

		for (int j = 0; j < length - 1; j++) {
			(*input)[i][j] = (char) (rand() % 26 + 97);
		}
		(*input)[i][length - 1] = '\0';
	}
}

int main(int argc, char *argv[]) {

//    char* input[] = {"wala", "ala" , "lula", "luba", "luda" ,"Loda", "lala", "Lalaa", "srala", "bocian", "dziabag",
//                     "Tempor", "nostrud", "inermis", "te", "vel", "epicuri", "lobortis", "imperdiet", "nam", "ut", "eu",
//                     "mollis", "intellegam", "suscipiantur", "eam", "Nihil", "epicurei", "appellantur", "his", "ad",
//                     "consul", "bonorum", "denique", "qui", "an", "et", "nam", "dicit", "lobortis", "Te", "labores",
//                     "fierent", "mea", "at", "nec", "eloquentiam", "instructior", "delicatissimi", "nisl", "veritus",
//                     "inciderint", "ex", "ius", "Sit", "in", "quot", "velit", "sensibus", "ut", "lorem", "voluptua",
//                     "nec", "cum", "consul", "saperet", "an", "Eam", "ea", "probatus", "recteque", "Ea", "iudico",
//                     "exerci", "conceptam", "vis", "tempor", "graeco", "dictas", "pro", "an", "vel", "te", "elitr",
//                     "omnesque", "Dico", "adhuc", "vis", "ad", "natum", "debitis", "te", "eos", "quas", "singulis",
//                     "eam", "no", "Exerci", "oblique", "cotidieque", "nec", "ea", "has", "mazim", "elitr", "apeirian",
//                     "cu", "Vix", "feugiat", "voluptaria", "cu", "Laudem", "vocibus", "neglegentur", "ei", "usu", "odio",
//                     "legimus", "honestatis", "te", "eos", "mea", "ei", "singulis", "indoctum", "Nam", "choro",
//                     "graecis", "cu", "Quo", "hinc", "ancillae", "definitionem", "no", "Ne", "est", "noster",
//                     "consetetur", "reprehendunt", "cum", "te", "deleniti", "deserunt", "Vide", "duis", "quo", "te",
//                     "Quis", "assum", "quidam", "sea", "ne", "Id", "mea", "illum", "nusquam", "Hinc", "legimus",
//                     "accusamus", "qui", "at", "consul", "quaerendum", "no", "cum", "Et", "mel", "recteque", "reprimique",
//                     "an", "ius", "mutat", "feugiat", "urbanitas", "forensibus", "mel", "in", "Et", "mutat", "definiebas",
//                     "quaerendum", "pri", "ad", "sed", "fugit", "fabulas", "enim", "repudiandae", "mea", "ne", "Wisi",
//                     "omnium", "assentior", "mei", "ea", "nam", "an", "illum", "evertitur", "sint", "appellantur", "eam",
//                     "te", "Ne", "sale", "assentior", "posidonium", "eum", "mutat", "erant", "ut", "nam", "ius", "labores",
//                     "repudiandae", "ne", "Usu", "in", "perpetua", "consequat", "vis", "et", "veri", "definiebas", "Vix",
//                     "no", "vide", "molestie", "efficiantur", "at", "vero", "accumsan", "abhorreant", "mea", "nulla",
//                     "eruditi", "eos", "eu", "Eum", "sapientem", "adolescens", "deterruisset", "id", "sonet", "inimicus",
//                     "consequat", "sed", "ut", "His", "docendi", "intellegam", "at", "vis", "tacimates", "ocurreret",
//                     "an", "pri", "alia", "augue", "minimum", "no", "Novum", "noster", "ea", "eam", "Movet", "insolens",
//                     "vel", "te", "in", "dicam", "dicant", "debitis", "per", "mel", "te", "zril", "legere", "adversarium",
//                     "Eum", "lobortis", "prodesset", "ad", "Ne", "his", "accusam", "disputationi", "eam", "in", "probo",
//                     "nobis", "quaerendum", "Cu", "mel", "vidisse", "ancillae", "reprimique", "Pro", "no", "modo", "mutat",
//                     "Te", "vix", "suas", "duis", "appareat", "et", "vis", "solum", "impetus", "Sed", "ad", "numquam",
//                     "noluisse", "urbanitas", "vix", "accusamus", "ullamcorper", "te", "His", "no", "nibh", "voluptua",
//                     "facilisi", "duo", "eu", "congue", "graeci", "doctus", "Cum", "et", "stet", "choro", "conclusionemque",
//                     "audiam", "molestie", "ut", "duo", "No", "legimus", "vocibus", "eos", "has", "facilis", "nominavi",
//                     "ne", "An", "idque", "patrioque", "gloriatur", "sea", "an", "mei", "gloriatur", "reprehendunt",
//                     "sonet", "numquam", "ex", "eum", "Equidem", "perpetua", "appellantur", "per", "an", "vel", "ne",
//                     "liber", "causae", "referrentur", "Iusto", "essent", "sed", "in", "Ius", "ut", "illud", "fuisset",
//                     "assueverit", "no", "definiebas", "suscipiantur", "sit", "Mei", "in", "aeque", "assentior",
//                     "abhorreant", "nec", "causae", "animal", "expetenda", "ex", "Eius", "definitionem", "eu", "vim",
//                     "his", "utinam", "omnium", "assueverit", "at", "quo", "iriure", "scaevola", "no", "Pri", "quas",
//                     "sadipscing", "ne", "Ei", "zril", "civibus", "quo", "forensibus", "disputationi", "no", "his", "Vix",
//                     "ad", "lorem", "vocibus", "Solum", "oporteat", "at", "mei", "utinam", "audire", "sit", "eu", "et",
//                     "mea", "elitr", "erroribus", "ocurreret", "Has", "esse", "admodum", "disputando", "an", "mei", "veri",
//                     "appareat", "no", "tincidunt", "sententiae", "his", "id", "Eius", "facer", "appellantur", "ea", "mei",
//                     "cu", "augue", "nostrum", "ius", "Dictas", "meliore", "his", "ne", "modo", "suscipit", "facilisis",
//                     "eos", "in", "Ullum", "semper", "vis", "ex", "cum", "dicta", "decore", "ne", "Partem", "efficiantur",
//                     "sed", "id", "an", "dolor", "fuisset", "scripserit", "has", "Mucius", "mollis", "fuisset", "ei", "vix",
//                     "at", "pro", "reque", "repudiare"};
//    long n = sizeof(input) / sizeof(char*);

	if (argc != 2) {
		printf("Usage:\n%s <problem_size>\n", argv[0]);
		return -1;
	}

	char **input;
	long n = atol(argv[1]);

	generate_data(&input, n);

	printf("INPUT:\n");
	print(input, n);

	radix(n, input);

	printf("\nOUTPUT:\n");
	print(input, n);

	return 0;
}
