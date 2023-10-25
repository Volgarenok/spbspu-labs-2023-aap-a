namespace isaychev
{
  struct even_counter
  {
    even_counter();
    void evn_cnt(int);
    unsigned long long int get_res() const;

  private:
    unsigned long long int count;
    unsigned long long int max_count;
  };
}
