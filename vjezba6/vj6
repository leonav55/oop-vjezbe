#include <iostream>
#include <stdexcept>
#include <string>

class container {
private:
    int* data_;
    size_t size_;
    size_t capacity_;

public:
    container(size_t initial_capacity = 0);
    container(const container& other);  
    container(container&& other) noexcept;  

    ~container();

    container& operator=(const container& other);
    container& operator=(container&& other) noexcept;

    void push_back(int value);
    size_t size() const;
    size_t capacity() const;
    int& at(size_t index);
    const int& at(size_t index) const;
    void clear();
};

container::container(size_t initial_capacity)
    : data_(initial_capacity > 0 ? new int[initial_capacity] : nullptr),
    size_(0),
    capacity_(initial_capacity) {
    std::cout << "Default konstruktor pozvan (capacity: " << capacity_ << ")" << std::endl;
}

container::container(const container& other)
    : data_(other.capacity_ > 0 ? new int[other.capacity_] : nullptr),
    size_(other.size_),
    capacity_(other.capacity_) {
    std::cout << "Copy konstruktor pozvan (kopiranje " << size_ << " elemenata)" << std::endl;
    for (size_t i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

container::container(container&& other) noexcept
    : data_(other.data_),
    size_(other.size_),
    capacity_(other.capacity_) {
    std::cout << "Move konstruktor pozvan (premještanje " << size_ << " elemenata)" << std::endl;
    other.data_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
}

container::~container() {
    std::cout << "Destruktor pozvan (oslobađanje " << size_ << " elemenata, capacity: "
        << capacity_ << ")" << std::endl;
    delete[] data_;
}

container& container::operator=(const container& other) {
    if (this != &other) {
        std::cout << "Copy assignment operator pozvan" << std::endl;
        delete[] data_;

        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = capacity_ > 0 ? new int[capacity_] : nullptr;

        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

container& container::operator=(container&& other) noexcept {
    if (this != &other) {
        std::cout << "Move assignment operator pozvan" << std::endl;
        delete[] data_;

        data_ = other.data_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }
    return *this;
}

void container::push_back(int value) {
    if (size_ >= capacity_) {
        size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
        std::cout << "Realokacija: " << capacity_ << " -> " << new_capacity << std::endl;

        int* new_data = new int[new_capacity];

        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data_[i];
        }

        delete[] data_;

        data_ = new_data;
        capacity_ = new_capacity;
    }

    data_[size_++] = value;
}

size_t container::size() const {
    return size_;
}

size_t container::capacity() const {
    return capacity_;
}

int& container::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Indeks izvan granica!");
    }
    return data_[index];
}

const int& container::at(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Indeks izvan granica!");
    }
    return data_[index];
}

void container::clear() {
    std::cout << "clear() pozvan - brišenje " << size_ << " elemenata (zadržava capacity: "
        << capacity_ << ")" << std::endl;
    size_ = 0;
}


void funkcija_po_vrijednosti(container c) {
    std::cout << "\n=== Unutar funkcije koja prima po vrijednosti ===" << std::endl;
    std::cout << "Size: " << c.size() << ", Capacity: " << c.capacity() << std::endl;
}

container stvori_container() {
    std::cout << "\n=== Stvaranje containera u funkciji ===" << std::endl;
    container temp(5);
    temp.push_back(100);
    temp.push_back(200);
    temp.push_back(300);
    std::cout << "Vraćanje containera iz funkcije..." << std::endl;
    return temp;  
}

void ispisi_container(const container& c, const std::string& naziv) {
    std::cout << "\n=== Ispis containera: " << naziv << " ===" << std::endl;
    std::cout << "Size: " << c.size() << ", Capacity: " << c.capacity() << std::endl;
    if (c.size() > 0) {
        std::cout << "Elementi:" << std::endl;
        for (size_t i = 0; i < c.size(); ++i) {
            std::cout << "  [" << i << "] = " << c.at(i) << std::endl;
        }
    }
    else {
        std::cout << "Container je prazan." << std::endl;
    }
}

int main() 
{
    std::cout << "\n### 1. Default konstruktor i dodavanje elemenata ###" << std::endl;
    container original(2);  
    original.push_back(10);
    original.push_back(20);
    ispisi_container(original, "original");

    std::cout << "\n### 2. Copy konstruktor ###" << std::endl;
    container kopija(original);
    ispisi_container(kopija, "kopija");

    std::cout << "\n### 3. Move konstruktor ###" << std::endl;
    container premjesten = std::move(original);
    ispisi_container(premjesten, "premjesten");
    std::cout << "Original nakon move: size=" << original.size()
        << ", capacity=" << original.capacity() << std::endl;

    std::cout << "\n### 4. Prosljeđivanje po vrijednosti ###" << std::endl;
    funkcija_po_vrijednosti(kopija);
    std::cout << "Nakon povratka iz funkcije..." << std::endl;

    std::cout << "\n### 5. Vraćanje iz funkcije ###" << std::endl;
    container vracen = stvori_container();
    ispisi_container(vracen, "vracen");

    std::cout << "\n### 6. Realokacija memorije ###" << std::endl;
    container raste(1);  
    std::cout << "Dodavanje elemenata koji će uzrokovati realokaciju..." << std::endl;
    for (int i = 1; i <= 10; ++i) {
        std::cout << "push_back(" << i * 5 << "): ";
        raste.push_back(i * 5);
        std::cout << " -> size=" << raste.size() << ", capacity=" << raste.capacity() << std::endl;
    }
    ispisi_container(raste, "raste");

    std::cout << "\n### 7. Clear operacija ###" << std::endl;
    ispisi_container(raste, "prije clear");
    raste.clear();
    ispisi_container(raste, "nakon clear");

    std::cout << "\nDodavanje nakon clear..." << std::endl;
    raste.push_back(999);
    ispisi_container(raste, "nakon clear i novog push_back");
    return 0;
}
