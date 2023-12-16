#include "invoice_reader.hpp"

Company InvoiceReader::create_company_from_data(std::ifstream &data_file)
{
    std::string company_name;
    std::string company_tin;
    std::getline(data_file, company_name, ' ');
    std::getline(data_file, company_tin, '\n');
    return Company(company_name, company_tin);
}
Order InvoiceReader::create_order_from_data(std::ifstream &data_file)
{
    std::string id;
    std::string name;
    std::string price;
    std::string producer;
    std::string quantity;
    std::getline(data_file, id, ' ');
    std::getline(data_file, name, ' ');
    std::getline(data_file, price, ' ');
    std::getline(data_file, producer, ' ');
    std::getline(data_file, quantity, '\n');

    return Order(static_cast<uint32_t>(stoi(id)), Item(name, static_cast<long double>(stod(price)), producer), static_cast<size_t>(stoi(quantity)));
}
void InvoiceReader::create_invoice_file_from_data(std::string data_file_name, std::string result_file_name)
{
    std::ifstream data_file(data_file_name);
    if (!data_file)
    {
        throw std::invalid_argument("Cannot read from the given file");
    }

    std::ofstream result_file(result_file_name);
    if (!result_file)
    {
        throw std::invalid_argument("Cannot write to the given file");
    }
    while (data_file.good())
    {
        try
        {
            std::vector<std::string> order_vector;
            Company issuer = create_company_from_data(data_file);
            Company recipient = create_company_from_data(data_file);

            Invoice i1 = Invoice(issuer, recipient);
            while (data_file.peek() != '\n' && data_file.peek() != EOF)
            {
                Order order = create_order_from_data(data_file);
                i1.add_order(order);
            }
            result_file << i1 << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Invalid data" << '\n';
            std::cerr << e.what() << '\n';
        }
    }
}
