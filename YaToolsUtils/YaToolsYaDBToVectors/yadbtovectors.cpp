#include <Yatools.hpp>
#include <IModel.hpp>
#include <FlatBufferModel.hpp>
#include <Algo/Algo.hpp>


#include <string.h>
#include <memory>

int main(int argc, char** argv)
{
    globals::InitFileLogger(*globals::Get().logger, stdout);

    if (argc < 3)
    {
        fprintf(stderr, "Bad arguments\n"
                        "Usage :\n"
                        "yadbtovectors <flatbuffer> <target_file>\n");
        exit(-1);
    }

    const auto db1 = MakeFlatBufferModel(argv[1]);
    yadiff::AlgoCfg cfg;
    memset(&cfg, 0, sizeof cfg);
    cfg.Algo = yadiff::ALGO_VECTOR_SIGN;
    cfg.VectorSign.mapDestination = argv[2];
    yadiff::MakeDiffAlgo(cfg)->Prepare(*db1, *db1);
}
