# bencoding

> **Bencode** (pronounced like *B-encode*) is the encoding used by the [peer-to-peer](https://en.wikipedia.org/wiki/Peer-to-peer) file sharing system [BitTorrent](https://en.wikipedia.org/wiki/BitTorrent_(protocol)) for storing and transmitting loosely structured data.
>
> It supports four different types of values:
>
> - [byte strings](https://en.wikipedia.org/wiki/String_(computer_science)),
> - [integers](https://en.wikipedia.org/wiki/Integer),
> - [lists](https://en.wikipedia.org/wiki/List_(computing)), and
> - [dictionaries (associative arrays)](https://en.wikipedia.org/wiki/Associative_array).
>
> Bencoding is most commonly used in [torrent files](https://en.wikipedia.org/wiki/Torrent_file), and as such is part of the BitTorrent specification. These [metadata](https://en.wikipedia.org/wiki/Metadata) files are simply bencoded dictionaries.
>
> While less efficient than a pure binary encoding,[*citation needed*] bencoding is simple and (because numbers are encoded as text in decimal notation) is unaffected by [endianness](https://en.wikipedia.org/wiki/Endianness), which is important for a [cross-platform](https://en.wikipedia.org/wiki/Cross-platform) application like BitTorrent. It is also fairly flexible, as long as applications ignore unexpected dictionary keys, so that new ones can be added without creating incompatibilities.

> - Strings are length-prefixed base ten followed by a colon and the string. For example `4:spam` corresponds to 'spam'.
> - Integers are represented by an 'i' followed by the number in base 10 followed by an 'e'. For example `i3e`corresponds to 3 and `i-3e` corresponds to -3. Integers have no size limitation. `i-0e` is invalid. All encodings with a leading zero, such as `i03e`, are invalid, other than `i0e`, which of course corresponds to 0.
> - Lists are encoded as an 'l' followed by their elements (also bencoded) followed by an 'e'. For example `l4:spam4:eggse` corresponds to ['spam', 'eggs'].
> - Dictionaries are encoded as a 'd' followed by a list of alternating keys and their corresponding values followed by an 'e'. For example, `d3:cow3:moo4:spam4:eggse` corresponds to {'cow': 'moo', 'spam': 'eggs'} and `d4:spaml1:a1:bee` corresponds to {'spam': ['a', 'b']}. Keys must be strings and appear in sorted order (sorted as raw strings, not alphanumerics).

