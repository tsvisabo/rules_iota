#include "iota/models/bundle.hpp"
#include "iota/models/transaction.hpp"

int main(int, char*[])
{

    using namespace std::chrono;


    IOTA::Models::Transaction tx;
    IOTA::Models::Bundle bundle;

    tx.setAddress(
            "JURSJVFIECKJYEHPATCXADQGHABKOOEZCRUHLIDHPNPIGRCXBFBWVISWCF9ODWQKLXBKY9FA"
            "CCKVXRAGZ");
    auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch())
            .count();
    tx.setTrunkTransaction("JURSJVFIECKJYEHPATCXADQGHABKOOEZCRUHLIDHPNPIGRCXBFBWVISWCF9ODWQKLXBKY9FACCKVXRAGZ");
    tx.setBranchTransaction("JURSJVFIECKJYEHPATCXADQGHABKOOEZCRUHLIDHPNPIGRCXBFBWVISWCF9ODWQKLXBKY9FACCKVXRAGZ");
    tx.setTimestamp(timestamp);
    tx.setValue(0);

    bundle.addTransaction(tx, 1);
    bundle.finalize();

    return 0;
}
