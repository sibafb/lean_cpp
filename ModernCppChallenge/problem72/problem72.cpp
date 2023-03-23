/**
 * 値引きした価格を計算
 * 以下の値引き価格を計算するプログラムを書きなさい
 * - 一律-5％
 * - 品目ごとに一定量買うと-10%
 * - ある品目を１００ドル以上購入する場合に-１５％
 * - 注文全体に対する値引き
*/

class order
{
    public:
    order(){}
};
class order_line
{
    public:
    order_line(){}
};
class customer
{

};
class article
{

};

struct discount_type
{
    virtual double discount_percent(double const price, double const quantity) const noexcept = 0;
    
};

struct fixed_discount : public discount_type 
{
    fixed_discount(const double discount) : discount(discount){}
    virtual double discount_percent(double const price, double const quantity) { return discount; }
private:
    const double discount;
};

struct volume_discount : public discount_type
{
    volume_discount(double const discount, double const min_quantity) : discount(discount),min_quantity(min_quantity){}
    virtual double discount_percent(double const price, double const quantity) { return quantity >= min_quantity ? discount : 0.0; }
private:
    double const discount;
    double const min_quantity;
};

struct amount_discount : public discount_type
{
    amount_discount(double const price, double const  discount) : discount(discount), min_total_price(price) {}
    virtual double discount_percent(double const price, double const discount) { return price >= min_total_price ? discount : 0.0; }
private:
    double const discount;
    double const min_total_price;
};

struct price_discount : public discount_type
{
    price_discount(const double &price , const double & discount) : discount(discount),min_total_price(price){}
    virtual double discount_percent(double const price, double const quantity) { return quantity * price >= min_total_price ? discount : 0.0; }
private: 
    double discount;
    double min_total_price;
};

int main()
{

}