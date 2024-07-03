#define TEST_CREATE_01 \
    do \
    { \
        try \
        { \
            Dictionary::Instance dict = Dictionary::Create(name, size); \
        } \
        catch (const std::length_error& e) \
        { \
            std::cerr << THROW01 << std::endl; \
        } \
    } while (0)

#define TEST_CREATE_02 \
    do \
    { \
        try \
        { \
            Dictionary::Instance dict = Dictionary::Create(name, 0); \
        } \
        catch (const std::overflow_error& e) \
        { \
            std::cerr << THROW02 << std::endl; \
        } \
    } while (0)

#define TEST_ADDENTRY_03 \
    do \
    { \
        try \
        { \
            Dictionary::AddEnrty(new_dictionary, inst, size_num); \
        } \
        catch (const std::exception& e) \
        { \
            std::cerr << THROW03 << std::endl; \
        } \
    } while (0)

#define TEST_ADDENTRY_04 \
    do \
    { \
        try \
        { \
            Dictionary::AddEnrty(new_dictionary, inst, size_num); \
        } \
        catch (const std::exception& e) \
        { \
            std::cerr << THROW04 << std::endl; \
        } \
    } while (0)

#define TEST_GETENTRY_05 \
    do \
    { \
        try \
        { \
            Dictionary::GetEntry(new_dictionary, id, size_num); \
        } \
        catch (const std::exception& e) \
        { \
            std::cerr << THROW05 << std::endl; \
        } \
    } while (0)

#define TEST_DEL_ENTRY_06 \
    do \
    { \
        try \
        { \
            Dictionary::DelEntry(new_dictionary, id, size_num); \
        } \
        catch (const std::exception& e) \
        { \
            std::cerr << THROW06 << std::endl; \
        } \
    } while (0)

#define TEST_UPD_ENTRY_07 \
    do \
    { \
        try \
        { \
            Dictionary::UpdEntry(new_dictionary, inst, size_num); \
        } \
        catch (const std::exception& e) \
        { \
            std::cerr << THROW07 << std::endl; \
        } \
    } while (0)

#define TEST_UPD_ENTRY_08 \
    do \
    { \
        try \
        { \
            Dictionary::UpdEntry(new_dictionary, inst, size_num); \
        } \
        catch (const std::exception& e) \
        { \
            std::cerr << THROW08 << std::endl; \
        } \
    } while (0)

#define TEST_DICTIONARY \
    do \
    { \
        try \
        { \
            std::cout << "Тестирование словаря" << std::endl; \
            const int MIN_ELEMENTS = 2; \
            const int NUM_DICTIONARIES = 2; \
            char name[DICTNAMEMAXSIZE]; \
            Dictionary::Instance dictionaries[NUM_DICTIONARIES]; \
            Dictionary::Entry entries[MIN_ELEMENTS]; \
            for (int i = 0; i < NUM_DICTIONARIES; ++i) \
            { \
                dictionaries[i] = Dictionary::Create(name, MIN_ELEMENTS); \
                for (int j = 0; j < MIN_ELEMENTS; ++j) \
                { \
                    Dictionary::AddEnrty(&dictionaries[i], entries, MIN_ELEMENTS); \
                } \
            } \
            std::cout << "Dictionary::UpdEntry(dictionaries, entries, MIN_ELEMENTS);" << std::endl; \
            Dictionary::UpdEntry(dictionaries, entries, MIN_ELEMENTS);\
            std::cout << "Dictionary::GetEntry(dictionaries, 1, MIN_ELEMENTS);" << std::endl; \
            Dictionary::GetEntry(dictionaries, 1, MIN_ELEMENTS);\
            std::cout << "Dictionary::DelEntry(dictionaries, 2, MIN_ELEMENTS);" << std::endl; \
            Dictionary::DelEntry(dictionaries, 2, MIN_ELEMENTS);\
            Dictionary::Print(dictionaries, NUM_DICTIONARIES); \
            std::cout << "Тестирование завершено успешно" << std::endl; \
        } \
        catch (const std::exception& e)\
        {\
            std::cout << "Произошла ошибка: " << e.what() << std::endl;\
        }\
    } while (0)