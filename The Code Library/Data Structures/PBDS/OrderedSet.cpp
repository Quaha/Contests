#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename set_type> using ordered_set = tree<
    set_type,
    null_type,
    std::less<set_type>, // std::greater<set_type>
    rb_tree_tag,
    tree_order_statistics_node_update
>;