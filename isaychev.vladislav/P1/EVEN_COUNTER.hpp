namespace isaychev
{
  class Even_counter
  {
    unsigned long long int count;
    unsigned long long int max_count;

  public:
    Even_counter();
    void operator()(int c_num);
    unsigned long long int operator()() const;
  };
}
