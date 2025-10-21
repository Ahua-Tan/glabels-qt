project (Merge LANGUAGES CXX)

#=====================================
# Sources
#=====================================
set (merge_sources
  Factory.cpp
  Record.cpp
  Merge.cpp
  None.cpp
  Text.cpp
  TextCsv.cpp
  TextCsvKeys.cpp
  TextTsv.cpp
  TextTsvKeys.cpp
  TextColon.cpp
  TextColonKeys.cpp
  TextSemicolon.cpp
  TextSemicolonKeys.cpp
)

set (merge_qobject_headers
  Merge.h
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt6_wrap_cpp(merge_moc_sources ${merge_qobject_headers})
else()
    qt5_wrap_cpp(merge_moc_sources ${merge_qobject_headers})
endif()

#=====================================
# Target
#=====================================
add_library (Merge STATIC
  ${merge_sources}
  ${merge_moc_sources}
)

#target_compile_features (Merge
#  PUBLIC cxx_std_11
#)
set_property (TARGET Merge PROPERTY CXX_STANDARD 11)

target_include_directories (Merge
  PUBLIC ..
)

target_link_libraries (Merge
  Qt${QT_VERSION_MAJOR}::Core
)
