#include <iostream>
#include <vector>
#include <string>
#include <memory>

enum class RoomType {
    STANDARD,
    DELUXE,
    LUXURY
};

struct Capacity {
    int adults;
    int children;
};

class PhongKhachSan {
protected:
    std::string tenPhong;
    Capacity sucChua;

public:
    PhongKhachSan(std::string name, int adultCount = 2, int childCount = 1)
        : tenPhong(std::move(name)), sucChua{adultCount, childCount} {}

    virtual ~PhongKhachSan() = default;

    virtual void hienThi() const {
        std::cout << "Loai phong: " << tenPhong << "\n"
                  << " - Nguoi lon: " << sucChua.adults << "\n"
                  << " - Tre em: " << sucChua.children << "\n";
    }
};

class PhongStandard : public PhongKhachSan {
public:
    PhongStandard() : PhongKhachSan("Standard Room") {}

    void hienThi() const override {
        PhongKhachSan::hienThi();
    }
};

class PhongDeluxe : public PhongKhachSan {
private:
    int giungDonLon;
    int giuongDoi;

public:
    PhongDeluxe(int donLon = 1, int doi = 2)
        : PhongKhachSan("Deluxe Room"), giungDonLon(donLon), giuongDoi(doi) {}

    void hienThi() const override {
        PhongKhachSan::hienThi();
        std::cout << " - Giuong don lon: " << giungDonLon << "\n"
                  << " - Giuong doi: " << giuongDoi << "\n";
    }
};

class PhongLuxury : public PhongKhachSan {
private:
    bool phongTamRieng;

public:
    PhongLuxury(bool coPhongTam = true)
        : PhongKhachSan("Luxury Room"), phongTamRieng(coPhongTam) {}

    void hienThi() const override {
        PhongKhachSan::hienThi();
        std::cout << " - Phong tam rieng: " << (phongTamRieng ? "Co" : "Khong") << "\n";
    }
};

int main() {
    std::vector<std::unique_ptr<PhongKhachSan>> dsPhong;

    dsPhong.push_back(std::make_unique<PhongStandard>());
    dsPhong.push_back(std::make_unique<PhongDeluxe>());
    dsPhong.push_back(std::make_unique<PhongLuxury>());

    for (const auto& p : dsPhong) {
        p->hienThi();
        std::cout << "-----------------------\n";
    }

    return 0;
}
