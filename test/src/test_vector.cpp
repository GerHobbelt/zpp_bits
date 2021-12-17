#include "test.h"

TEST(vector, integer)
{
    auto [data, in, out] = zpp::bits::data_in_out();
    out(std::vector{1,2,3,4}).or_throw();

    EXPECT_EQ(hexlify(data),
              "04000000"
              "01000000"
              "02000000"
              "03000000"
              "04000000");

    std::vector<int> v;
    in(v).or_throw();

    EXPECT_EQ(v, (std::vector{1,2,3,4}));
}

TEST(vector, const_integer)
{
    auto [data, in, out] = zpp::bits::data_in_out();
    const std::vector<const int> o{1,2,3,4};
    out(o).or_throw();

    EXPECT_EQ(hexlify(data),
              "04000000"
              "01000000"
              "02000000"
              "03000000"
              "04000000");

    std::vector<int> v;
    in(v).or_throw();

    EXPECT_EQ(v, (std::vector{1,2,3,4}));
}

TEST(vector, string)
{
    using namespace std::string_literals;
    auto [data, in, out] = zpp::bits::data_in_out();
    out(std::vector{"1"s,"2"s,"3"s,"4"s}).or_throw();

    EXPECT_EQ(hexlify(data),
              "04000000"
              "01000000"
              "31"
              "01000000"
              "32"
              "01000000"
              "33"
              "01000000"
              "34");

    std::vector<std::string> v;
    in(v).or_throw();

    EXPECT_EQ(v, (std::vector{"1"s,"2"s,"3"s,"4"s}));
}

TEST(vector, const_string)
{
    using namespace std::string_literals;
    auto [data, in, out] = zpp::bits::data_in_out();
    const std::vector<const std::string> o{"1"s, "2"s, "3"s, "4"s};
    out(o).or_throw();

    EXPECT_EQ(hexlify(data),
              "04000000"
              "01000000"
              "31"
              "01000000"
              "32"
              "01000000"
              "33"
              "01000000"
              "34");

    std::vector<std::string> v;
    in(v).or_throw();

    EXPECT_EQ(v, (std::vector{"1"s,"2"s,"3"s,"4"s}));
}

TEST(vector, sized_1b_integer)
{
    auto [data, in, out] = zpp::bits::data_in_out();
    out(zpp::bits::sized<std::uint8_t>(std::vector{1,2,3,4})).or_throw();

    EXPECT_EQ(hexlify(data),
              "04"
              "01000000"
              "02000000"
              "03000000"
              "04000000");

    std::vector<int> v;
    in(zpp::bits::sized<std::uint8_t>(v)).or_throw();

    EXPECT_EQ(v, (std::vector{1,2,3,4}));
}

TEST(vector, unsized_integer)
{
    auto [data, in, out] = zpp::bits::data_in_out();
    out(zpp::bits::unsized(std::vector{1,2,3,4})).or_throw();

    EXPECT_EQ(hexlify(data),
              "01000000"
              "02000000"
              "03000000"
              "04000000");

    std::vector<int> v(4);
    in(zpp::bits::unsized(v)).or_throw();

    EXPECT_EQ(v, (std::vector{1,2,3,4}));
}

