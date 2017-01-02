// Le bloc ifdef suivant est la façon standard de créer des macros qui facilitent l'exportation 
// à partir d'une DLL. Tous les fichiers contenus dans cette DLL sont compilés avec le symbole INPUTOUTPUTLIBRARY_EXPORTS
// défini sur la ligne de commande. Ce symbole ne doit pas être défini pour un projet
// qui utilisent cette DLL. De cette manière, les autres projets dont les fichiers sources comprennent ce fichier considèrent les fonctions 
// INPUTOUTPUTLIBRARY_API comme étant importées à partir d'une DLL, tandis que cette DLL considère les symboles
// définis avec cette macro comme étant exportés.
#ifdef INPUTOUTPUTLIBRARY_EXPORTS
#define INPUTOUTPUTLIBRARY_API __declspec(dllexport)
#else
#define INPUTOUTPUTLIBRARY_API __declspec(dllimport)
#endif

// Cette classe est exportée de InputOutputLibrary.dll
class INPUTOUTPUTLIBRARY_API CInputOutputLibrary {
public:
	CInputOutputLibrary(void);
	// TODO: ajoutez ici vos méthodes.
};

extern INPUTOUTPUTLIBRARY_API int nInputOutputLibrary;

//INPUTOUTPUTLIBRARY_API int fnInputOutputLibrary(void);
INPUTOUTPUTLIBRARY_API int mp3_to_wav(wchar_t* sourcefile, wchar_t* destinationfile);
