class GeometricSequence
{
private:
    double a1;
    double q;

public:
    GeometricSequence(double starting_a1, double starting_q);
    double get_a1() const;
    double get_q() const;

    void set_a1(double new_a1);
    void set_q(double new_q);

    double get_nth_element(int n) const;
    double get_sum_of_first_n_elements(int n) const;
};