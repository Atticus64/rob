#include "file.cpp"
#include "args.cpp"

auto main(int argc, char* argv[]) -> int {

	parse_args(argc, argv);

	/* auto db = parse_csv("foo.csv"); */
	/*  */
	/* for(auto& item : db) { */
	/*     std::cout << item.first << ' ' << item.second << std::endl; */
	/*   } */
	/*  */
	/* db.erase("mid"); */
	/* std::cout << "--------------------\n"; */
	/*  */
	/* for(auto& item : db) { */
	/*     std::cout << item.first << ' ' << item.second << std::endl; */
	/*   } */
	/*  */
	return 0;
}

