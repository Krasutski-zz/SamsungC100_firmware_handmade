SECTIONS
{
.entry 0x400000 : {
   __entry_start = .;
   *(.entry)
   __entry_end = .;
}

} 