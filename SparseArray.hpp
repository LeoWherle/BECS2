

#include <algorithm> // for std::find
#include <optional> // for std::optional
#include <type_traits> // for std::is_default_constructible
#include <vector> // for std::vector

template<typename T>
concept isComponent = std::is_default_constructible<T>::value;

// You can also mirror the definition of std :: vector that takes an additional
// allocator.
template<typename T, typename A = std::allocator<T>>
class SparseArray {
public:
    using value_type = std::optional<T>;
    using reference_type = value_type &;
    using const_reference_type = const value_type &;
    using container_t = std ::vector<value_type, A>; // optionally add your allocator
    using size_type = typename container_t::size_type;
    using iterator = typename container_t::iterator;
    using const_iterator = typename container_t::const_iterator;

public:
    SparseArray() = default;
    SparseArray(const SparseArray &) = default;
    SparseArray(SparseArray &&) noexcept = default;
    ~SparseArray() = default;
    SparseArray &operator=(const SparseArray &) = default;
    SparseArray &operator=(SparseArray &&) noexcept = default;

    inline auto operator[](size_t idx) -> reference_type { return _data[idx]; }
    inline auto operator[](size_t idx) const -> const_reference_type { return _data[idx]; }
    auto begin() -> iterator { return _data.begin(); }
    auto begin() const -> const_iterator { return _data.begin(); }
    inline auto cbegin() const -> const_iterator { return _data.cbegin(); }
    inline auto end() -> iterator { return _data.end(); }
    inline auto end() const -> const_iterator { return _data.end(); }
    inline auto cend() const -> const_iterator { return _data.end(); }
    inline auto size() const -> size_type { return _data.size(); }
    inline auto insert(size_type pos, const T &value) -> reference_type
    {
        _data.insert(_data.begin() + pos, value);
        return _data[pos];
    }
    inline auto insert(size_type pos, T &&value) -> reference_type
    {
        _data.insert(_data.begin() + pos, std::move(value));
        return _data[pos];
    }

    template<class... Params>
    inline auto emplace(size_type pos, Params &&...) -> reference_type
    {
        _data.emplace(_data.begin() + pos, std::nullopt);
    }

    inline void erase(size_type pos) { _data[pos].reset(); }
    inline void clear() { _data.clear(); }

private:
    container_t _data;
};