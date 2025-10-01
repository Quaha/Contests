#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename set_type> using ordered_multiset = tree<
    set_type,
    null_type,
    std::less_equal<set_type>, // std::greater_equal<set_type>
    rb_tree_tag,
    tree_order_statistics_node_update
>;