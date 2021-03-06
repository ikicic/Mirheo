#pragma once

#include <string>
#include <vector>

#include <mpi.h>
#include <extern/pugixml/src/pugixml.hpp>

#include "grids.h"

namespace XDMF
{
namespace XMF
{        

void writeDataSet(pugi::xml_node node, const std::string& h5filename,
                  const Grid *grid, const Channel& channel);
void writeData   (pugi::xml_node node, const std::string& h5filename, const Grid *grid,
                  const std::vector<Channel>& channels);
void write(const std::string& filename, const std::string& h5filename, MPI_Comm comm,
           const Grid *grid, const std::vector<Channel>& channels, float time);

std::tuple<std::string /*h5filename*/, std::vector<Channel>>
read(const std::string& filename, MPI_Comm comm, Grid *grid);

} // namespace XMF
} // namespace XDMF
