#include <vector>
#include <iostream>
#include <fstream>
#include <exception>
#include "invoice.hpp"

class InvoiceReader
{
private:
    static Company create_company_from_data(std::ifstream &data_file);
    static Order create_order_from_data(std::ifstream &data_file);

public:
    static void create_invoice_file_from_data(std::string data_file_name, std::string result_file_name);
};