defmodule Conv do
  def bin_to_hex(b) do
	bin_to_hex_rec(b, [])
  end

  defp bin_to_hex_rec(before, aft) when before != "" do
  	{b, a} = String.split_at(before, -4)
	s = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"] 
	bin_to_hex_rec(b, [Enum.at(s, bin_to_dec(a)) | aft])
  end

  defp bin_to_hex_rec("", aft) do
    aft
  end

  def bin_to_dec(b) do
    bin_to_dec_rec(b, 0, 0)
  end

  defp bin_to_dec_rec(before, aft, i) when before != "" do
    {b, a} = String.split_at(before, -1)
    bin_to_dec_rec(b, case a do
      "0" -> aft
      "1" -> aft + Integer.pow(2, i)
    end, i + 1)
  end

  defp bin_to_dec_rec("", aft, _i) do
    aft
  end
end

Conv.bin_to_hex("1111")
|> IO.puts() # must print f

Conv.bin_to_hex("11101011")
|> IO.puts() # must print EB

