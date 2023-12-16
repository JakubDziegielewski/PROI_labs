#include "src/company.hpp"
#include "src/order.hpp"
#include "src/invoice.hpp"
#include "src/invoice_reader.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <exception>

int main()
{
    std::string data_file_name;
    std::string result_file_name;
    std::cout << "Enter data file name: ";
    std::cin >> data_file_name;
    std::cout << std::endl;
    std::cout << "Enter result file name: ";
    std::cin >> result_file_name;
    std::cout << std::endl;
    try
    {
        InvoiceReader::create_invoice_file_from_data(data_file_name, result_file_name);
    }
    catch (std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
