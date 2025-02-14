#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wrapper_header_collection.hpp"

#include "Vertex.cppwg.hpp"

namespace py = pybind11;
//typedef TopologicCore::Vertex Vertex;
PYBIND11_DECLARE_HOLDER_TYPE(T, std::shared_ptr<T>);
typedef ::TopoDS_Shape & _TopoDS_ShapeRef;
typedef ::TopoDS_Shape const & _TopoDS_ShapeconstRef;
typedef ::TopoDS_Vertex & _TopoDS_VertexRef;
typedef ::TopoDS_Vertex const & _TopoDS_VertexconstRef;
typedef ::std::shared_ptr<TopologicCore::Vertex> _std_shared_ptr_lt_TopologicCore_Vertex_gt_;
typedef ::TopologicCore::TopologyType _TopologicCore_TopologyType;
typedef ::std::string _std_string;
typedef ::std::string _std_string;

class Vertex_Overloads : public Vertex{
    public:
    using Vertex::Vertex;
    bool IsManifold() const  override {
        PYBIND11_OVERLOAD(
            bool,
            Vertex,
            IsManifold,
            );
    }
    void Geometry(::std::list<opencascade::handle<Geom_Geometry>, std::allocator<opencascade::handle<Geom_Geometry>>> & rOcctGeometries) const  override {
        PYBIND11_OVERLOAD(
            void,
            Vertex,
            Geometry,
            rOcctGeometries);
    }
    ::TopoDS_Shape & GetOcctShape() override {
        PYBIND11_OVERLOAD(
            _TopoDS_ShapeRef,
            Vertex,
            GetOcctShape,
            );
    }
    ::TopoDS_Shape const & GetOcctShape() const  override {
        PYBIND11_OVERLOAD(
            _TopoDS_ShapeconstRef,
            Vertex,
            GetOcctShape,
            );
    }
    void SetOcctShape(::TopoDS_Shape const & rkOcctShape) override {
        PYBIND11_OVERLOAD(
            void,
            Vertex,
            SetOcctShape,
            rkOcctShape);
    }
    ::TopoDS_Vertex & GetOcctVertex() override {
        PYBIND11_OVERLOAD(
            _TopoDS_VertexRef,
            Vertex,
            GetOcctVertex,
            );
    }
    ::TopoDS_Vertex const & GetOcctVertex() const  override {
        PYBIND11_OVERLOAD(
            _TopoDS_VertexconstRef,
            Vertex,
            GetOcctVertex,
            );
    }
    ::std::shared_ptr<TopologicCore::Vertex> CenterOfMass() const  override {
        PYBIND11_OVERLOAD(
            _std_shared_ptr_lt_TopologicCore_Vertex_gt_,
            Vertex,
            CenterOfMass,
            );
    }
    ::TopologicCore::TopologyType GetType() const  override {
        PYBIND11_OVERLOAD(
            _TopologicCore_TopologyType,
            Vertex,
            GetType,
            );
    }
    ::std::string GetTypeAsString() const  override {
        PYBIND11_OVERLOAD(
            _std_string,
            Vertex,
            GetTypeAsString,
            );
    }
    ::std::string GetClassGUID() const  override {
        PYBIND11_OVERLOAD(
            _std_string,
            Vertex,
            GetClassGUID,
            );
    }
    bool IsContainerType() override {
        PYBIND11_OVERLOAD(
            bool,
            Vertex,
            IsContainerType,
            );
    }

};
void register_Vertex_class(py::module &m){
py::class_<Vertex , Vertex_Overloads , std::shared_ptr<Vertex >  , Topology  >(m, "Vertex")
        .def(py::init<::TopoDS_Vertex const &, ::std::string const & >(), py::arg("rkOcctVertex"), py::arg("rkGuid") = "")
        .def_static(
            "ByPoint", 
            (::std::shared_ptr<TopologicCore::Vertex>(*)(::opencascade::handle<Geom_Point>)) &Vertex::ByPoint, 
            " " , py::arg("pOcctPoint") )
        .def_static(
            "ByCoordinates", 
            (::std::shared_ptr<TopologicCore::Vertex>(*)(double const, double const, double const)) &Vertex::ByCoordinates, 
            " " , py::arg("kX"), py::arg("kY"), py::arg("kZ") )
        /*.def(
            "Edges", 
            (void(Vertex::*)(::std::list<std::shared_ptr<TopologicCore::Edge>, std::allocator<std::shared_ptr<TopologicCore::Edge>>> &)) &Vertex::Edges, 
            " " , py::arg("rEdges") ) */
        .def(
            // Proof of concept for list passed as reference and filled in C++
            "Edges",
            [](Vertex& obj, py::list& rEdges) {
                std::list<Edge::Ptr> local;
                obj.Edges(local);
                for (auto& x : local)
                    rEdges.append(x);
            },
            " ", py::arg("rEdges"))
        .def(
            "X", 
            (double(Vertex::*)() const ) &Vertex::X, 
            " "  )
        .def(
            "Y", 
            (double(Vertex::*)() const ) &Vertex::Y, 
            " "  )
        .def(
            "Z", 
            (double(Vertex::*)() const ) &Vertex::Z, 
            " "  )
        .def(
            "Coordinates", 
            (::std::tuple<double, double, double>(Vertex::*)() const ) &Vertex::Coordinates, 
            " "  )
        .def(
            "IsManifold", 
            (bool(Vertex::*)() const ) &Vertex::IsManifold, 
            " "  )
        .def(
            "Geometry", 
            (void(Vertex::*)(::std::list<opencascade::handle<Geom_Geometry>, std::allocator<opencascade::handle<Geom_Geometry>>> &) const ) &Vertex::Geometry, 
            " " , py::arg("rOcctGeometries") )
        .def(
            "GetOcctShape", 
            (::TopoDS_Shape &(Vertex::*)()) &Vertex::GetOcctShape, 
            " "  )
        .def(
            "GetOcctShape", 
            (::TopoDS_Shape const &(Vertex::*)() const ) &Vertex::GetOcctShape, 
            " "  )
        .def(
            "SetOcctShape", 
            (void(Vertex::*)(::TopoDS_Shape const &)) &Vertex::SetOcctShape, 
            " " , py::arg("rkOcctShape") )
        .def(
            "GetOcctVertex", 
            (::TopoDS_Vertex &(Vertex::*)()) &Vertex::GetOcctVertex, 
            " "  )
        .def(
            "SetOcctVertex", 
            (void(Vertex::*)(::TopoDS_Vertex const &)) &Vertex::SetOcctVertex, 
            " " , py::arg("rkOcctVertex") )
        .def(
            "GetOcctVertex", 
            (::TopoDS_Vertex const &(Vertex::*)() const ) &Vertex::GetOcctVertex, 
            " "  )
        .def(
            "Point", 
            (::opencascade::handle<Geom_Point>(Vertex::*)() const ) &Vertex::Point, 
            " "  )
        .def(
            "CenterOfMass", 
            (::std::shared_ptr<TopologicCore::Vertex>(Vertex::*)() const ) &Vertex::CenterOfMass, 
            " "  )
        .def(
            "GetType", 
            (::TopologicCore::TopologyType(Vertex::*)() const ) &Vertex::GetType, 
            " "  )
        .def(
            "GetTypeAsString", 
            (::std::string(Vertex::*)() const ) &Vertex::GetTypeAsString, 
            " "  )
        .def(
            "GetClassGUID", 
            (::std::string(Vertex::*)() const ) &Vertex::GetClassGUID, 
            " "  )
        .def_static(
            "Type", 
            (int(*)()) &Vertex::Type, 
            " "  )
        .def(
            "IsContainerType", 
            (bool(Vertex::*)()) &Vertex::IsContainerType, 
            " "  )
    ;
}
