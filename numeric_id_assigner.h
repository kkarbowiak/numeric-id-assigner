#ifndef NUMERIC_ID_ASSIGNER
#define NUMERIC_ID_ASSIGNER

#include <map>
#include <limits>
#include <cstddef>


template<typename I, typename O>
class numeric_id_assigner
{
    public:
        numeric_id_assigner();

        void add(I id);
        O get(I id) const;

        std::size_t size() const;

    private:
        std::map<I, O> assignments;
        O current;
};

////////////////////////////////////////////////////////////////////////////////
template<typename I, typename O>
inline numeric_id_assigner<I, O>::numeric_id_assigner()
  : assignments()
  , current(0)
{
}
////////////////////////////////////////////////////////////////////////////////
template<typename I, typename O>
inline void numeric_id_assigner<I, O>::add(I id)
{
    if (assignments.count(id) == 0)
    {
        assignments[id] = current++;
    }
}
////////////////////////////////////////////////////////////////////////////////
template<typename I, typename O>
inline O numeric_id_assigner<I, O>::get(I id) const
{
    auto const it = assignments.find(id);
    if (it != assignments.end())
    {
        return it->second;
    }
    else
    {
        return std::numeric_limits<O>::max();
    }
}
////////////////////////////////////////////////////////////////////////////////
template<typename I, typename O>
inline std::size_t numeric_id_assigner<I, O>::size() const
{
    return assignments.size();
}
////////////////////////////////////////////////////////////////////////////////

#endif /* NUMERIC_ID_ASSIGNER */

