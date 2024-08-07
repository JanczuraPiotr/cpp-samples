//
// Created by piotr@janczura.pl on 2024.06.09
//

#include <chrono>
#include <memory>
#include <vector>
#include <iostream>
#include <iomanip>

class Int1 {
public:
    using TC = Int1;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "Int1";};

    Int1() : _a1(0) {};

private:
    int _a1;
};

class Int2 {
public:
    using TC = Int2;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "Int2";};

    Int2() : _a1(0), _a2(0) {};
//    Int2(int i1, int i2) : _a1(i1), _a2(i2) {};

private:
    int _a1;
    int _a2;

};

class Int10 {
public:
    using TC = Int10;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name()
    { return "Int10"; };

    Int10() : _a1(0), _a2(0), _a3(0), _a4(0), _a5(0), _a6(0), _a7(0), _a8(0), _a9(0), _a10(0)
    {};

private:
    int _a1, _a2, _a3, _a4, _a5, _a6, _a7, _a8, _a9, _a10;
};

class Int100 {
public:
    using TC = Int100;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name()
    { return "Int100"; };

    Int100()
        :  _a001(0), _a002(0), _a003(0), _a004(0), _a005(0), _a006(0), _a007(0), _a008(0), _a009(0), _a010(0),
           _a011(0), _a012(0), _a013(0), _a014(0), _a015(0), _a016(0), _a017(0), _a018(0), _a019(0), _a020(0),
           _a021(0), _a022(0), _a023(0), _a024(0), _a025(0), _a026(0), _a027(0), _a028(0), _a029(0), _a030(0),
           _a031(0), _a032(0), _a033(0), _a034(0), _a035(0), _a036(0), _a037(0), _a038(0), _a039(0), _a040(0),
           _a041(0), _a042(0), _a043(0), _a044(0), _a045(0), _a046(0), _a047(0), _a048(0), _a049(0), _a050(0),
           _a051(0), _a052(0), _a053(0), _a054(0), _a055(0), _a056(0), _a057(0), _a058(0), _a059(0), _a060(0),
           _a061(0), _a062(0), _a063(0), _a064(0), _a065(0), _a066(0), _a067(0), _a068(0), _a069(0), _a070(0),
           _a071(0), _a072(0), _a073(0), _a074(0), _a075(0), _a076(0), _a077(0), _a078(0), _a079(0), _a080(0),
           _a081(0), _a082(0), _a083(0), _a084(0), _a085(0), _a086(0), _a087(0), _a088(0), _a089(0), _a090(0),
           _a091(0), _a092(0), _a093(0), _a094(0), _a095(0), _a096(0), _a097(0), _a098(0), _a099(0), _a100(0)
    {};

private:
    int _a001, _a002, _a003, _a004, _a005, _a006, _a007, _a008, _a009, _a010,
        _a011, _a012, _a013, _a014, _a015, _a016, _a017, _a018, _a019, _a020,
        _a021, _a022, _a023, _a024, _a025, _a026, _a027, _a028, _a029, _a030,
        _a031, _a032, _a033, _a034, _a035, _a036, _a037, _a038, _a039, _a040,
        _a041, _a042, _a043, _a044, _a045, _a046, _a047, _a048, _a049, _a050,
        _a051, _a052, _a053, _a054, _a055, _a056, _a057, _a058, _a059, _a060,
        _a061, _a062, _a063, _a064, _a065, _a066, _a067, _a068, _a069, _a070,
        _a071, _a072, _a073, _a074, _a075, _a076, _a077, _a078, _a079, _a080,
        _a081, _a082, _a083, _a084, _a085, _a086, _a087, _a088, _a089, _a090,
        _a091, _a092, _a093, _a094, _a095, _a096, _a097, _a098, _a099, _a100
        ;
};

class Double10 {
public:
    using TC = Double10;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "Double10";};

    Double10()
        : _a001(0.0), _a002(0.0), _a003(0.0), _a004(0.0), _a005(0.0), _a006(0.0), _a007(0.0), _a008(0.0), _a009(0.0), _a010(0.0)
    {};

private:
    double _a001, _a002, _a003, _a004, _a005, _a006, _a007, _a008, _a009, _a010;
};

class Double50 {
public:
    using TC = Double50;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "Double50";};

    Double50()
        : _a001(0.0), _a002(0.0), _a003(0.0), _a004(0.0), _a005(0.0), _a006(0.0), _a007(0.0), _a008(0.0), _a009(0.0), _a010(0.0),
          _a011(0.0), _a012(0.0), _a013(0.0), _a014(0.0), _a015(0.0), _a016(0.0), _a017(0.0), _a018(0.0), _a019(0.0), _a020(0.0),
          _a021(0.0), _a022(0.0), _a023(0.0), _a024(0.0), _a025(0.0), _a026(0.0), _a027(0.0), _a028(0.0), _a029(0.0), _a030(0.0),
          _a031(0.0), _a032(0.0), _a033(0.0), _a034(0.0), _a035(0.0), _a036(0.0), _a037(0.0), _a038(0.0), _a039(0.0), _a040(0.0),
          _a041(0.0), _a042(0.0), _a043(0.0), _a044(0.0), _a045(0.0), _a046(0.0), _a047(0.0), _a048(0.0), _a049(0.0), _a050(0.0)
    {};

private:
    double _a001, _a002, _a003, _a004, _a005, _a006, _a007, _a008, _a009, _a010,
           _a011, _a012, _a013, _a014, _a015, _a016, _a017, _a018, _a019, _a020,
           _a021, _a022, _a023, _a024, _a025, _a026, _a027, _a028, _a029, _a030,
           _a031, _a032, _a033, _a034, _a035, _a036, _a037, _a038, _a039, _a040,
           _a041, _a042, _a043, _a044, _a045, _a046, _a047, _a048, _a049, _a050
           ;
};

class Double100 {
public:
    using TC = Double100;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "Double100";};

    Double100()
        : _a001(0.0), _a002(0.0), _a003(0.0), _a004(0.0), _a005(0.0), _a006(0.0), _a007(0.0), _a008(0.0), _a009(0.0), _a010(0.0),
          _a011(0.0), _a012(0.0), _a013(0.0), _a014(0.0), _a015(0.0), _a016(0.0), _a017(0.0), _a018(0.0), _a019(0.0), _a020(0.0),
          _a021(0.0), _a022(0.0), _a023(0.0), _a024(0.0), _a025(0.0), _a026(0.0), _a027(0.0), _a028(0.0), _a029(0.0), _a030(0.0),
          _a031(0.0), _a032(0.0), _a033(0.0), _a034(0.0), _a035(0.0), _a036(0.0), _a037(0.0), _a038(0.0), _a039(0.0), _a040(0.0),
          _a041(0.0), _a042(0.0), _a043(0.0), _a044(0.0), _a045(0.0), _a046(0.0), _a047(0.0), _a048(0.0), _a049(0.0), _a050(0.0),
          _a051(0.0), _a052(0.0), _a053(0.0), _a054(0.0), _a055(0.0), _a056(0.0), _a057(0.0), _a058(0.0), _a059(0.0), _a060(0.0),
          _a061(0.0), _a062(0.0), _a063(0.0), _a064(0.0), _a065(0.0), _a066(0.0), _a067(0.0), _a068(0.0), _a069(0.0), _a070(0.0),
          _a071(0.0), _a072(0.0), _a073(0.0), _a074(0.0), _a075(0.0), _a076(0.0), _a077(0.0), _a078(0.0), _a079(0.0), _a080(0.0),
          _a081(0.0), _a082(0.0), _a083(0.0), _a084(0.0), _a085(0.0), _a086(0.0), _a087(0.0), _a088(0.0), _a089(0.0), _a090(0.0),
          _a091(0.0), _a092(0.0), _a093(0.0), _a094(0.0), _a095(0.0), _a096(0.0), _a097(0.0), _a098(0.0), _a099(0.0), _a100(0.0)
    {};

private:
    double _a001, _a002, _a003, _a004, _a005, _a006, _a007, _a008, _a009, _a010,
           _a011, _a012, _a013, _a014, _a015, _a016, _a017, _a018, _a019, _a020,
           _a021, _a022, _a023, _a024, _a025, _a026, _a027, _a028, _a029, _a030,
           _a031, _a032, _a033, _a034, _a035, _a036, _a037, _a038, _a039, _a040,
           _a041, _a042, _a043, _a044, _a045, _a046, _a047, _a048, _a049, _a050,
           _a051, _a052, _a053, _a054, _a055, _a056, _a057, _a058, _a059, _a060,
           _a061, _a062, _a063, _a064, _a065, _a066, _a067, _a068, _a069, _a070,
           _a071, _a072, _a073, _a074, _a075, _a076, _a077, _a078, _a079, _a080,
           _a081, _a082, _a083, _a084, _a085, _a086, _a087, _a088, _a089, _a090,
           _a091, _a092, _a093, _a094, _a095, _a096, _a097, _a098, _a099, _a100
           ;
};

class Mixed1 {
public:
    using TC = Mixed1;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "Mixed1";};

    Mixed1()
        : _i1(10, 1)
        , _d1(10, 1.0)
        , _s1("2546tfy5urkm7o7ih5ywerrujbnyigtyjgfcrvrb")
    {};

private:
    std::vector<int> _i1;
    std::vector<double> _d1;
    std::string _s1;
};

class VectorInt {
public:
    using TC = VectorInt;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "VectorInt";};

    VectorInt()
        : _i1(10, 1)
    {};

private:
    std::vector<int> _i1;
};

class VectorDouble {
public:
    using TC = VectorDouble;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "VectorDouble";};

    VectorDouble()
        : _d1(10, 1.0)
    {};

private:
    std::vector<double> _d1;
};

class String {
public:
    using TC = String;
    using Vector = std::vector<TC>;
    using Shared = std::shared_ptr<TC>;
    using SharedVector = std::vector<Shared>;
    using Unique = std::unique_ptr<TC>;
    using UniqueVector = std::vector<Unique>;

    static std::string name() { return "String";};

    String()
        : _s1("2546tfy5urkm7o7ih5ywerrujbnyigtyjgfcrvrb")
    {};

private:
    std::string _s1;
};

template<typename MeasuredClass,
         typename Precision>
void loop(unsigned iterations, const std::string &precisionStr)
{

    constexpr unsigned namew{30};
    {
        std::cout << std::setw(namew) << std::left << MeasuredClass::name() + "::Vector";
        typename MeasuredClass::Vector vector;

        auto begin = std::chrono::steady_clock::now();

        for (unsigned i = 0; i < iterations; ++i) {
            vector.push_back(MeasuredClass());
        }

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<Precision>(end - begin);

        std::cout << std::setw(10) << std::right << "elapsed : " << std::setw(10) << std::right << elapsed.count() << precisionStr << std::endl;
    }

    {
        std::cout << std::setw(namew) << std::left << MeasuredClass::name() + "::SharedVector";
        typename MeasuredClass::SharedVector sharedVector;

        auto begin = std::chrono::steady_clock::now();

        for (unsigned i = 0; i < iterations; ++i) {
            sharedVector.push_back(std::make_shared<MeasuredClass>());
        }

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<Precision>(end - begin);

        std::cout << std::setw(10) << std::right << "elapsed : " << std::setw(10) << std::right << elapsed.count() << precisionStr << std::endl;
    }

    {
        std::cout << std::setw(namew) << std::left << MeasuredClass::name() + "::UniqueVector";
        typename MeasuredClass::UniqueVector uniqueVector;

        auto begin = std::chrono::steady_clock::now();

        for (unsigned i = 0; i < iterations; ++i) {
            uniqueVector.push_back(std::make_unique<MeasuredClass>());
        }

        auto end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<Precision>(end - begin);

        std::cout << std::setw(10) << std::right << "elapsed : " << std::setw(10) << std::right << elapsed.count() << precisionStr << std::endl;
    }

}

int main() {

//    constexpr int MILION = 1000000;
//    unsigned iterations = MILION * 3;
    unsigned iterations = 10 * 3;

//    using Precision = std::chrono::milliseconds;
//    std::string precisionStr{"[ms]"};

    using Precision = std::chrono::nanoseconds;
    const char *precisionStr = "[ns]";


    loop<Int1, Precision>(iterations, precisionStr);
    loop<Int2, Precision>(iterations, precisionStr);
    loop<Int10, Precision>(iterations, precisionStr);
    loop<Int100, Precision>(iterations, precisionStr);
    loop<Double10, Precision>(iterations, precisionStr);
    loop<Double50, Precision>(iterations, precisionStr);
    loop<Double100, Precision>(iterations, precisionStr);
    loop<Mixed1, Precision>(iterations, precisionStr);
    loop<VectorInt, Precision>(iterations, precisionStr);
    loop<VectorDouble, Precision>(iterations, precisionStr);
    loop<String, Precision>(iterations, precisionStr);

}