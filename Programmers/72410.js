const solution = (new_id) => {
  const new_id1 = new_id.toLowerCase();
  const new_id2 = new_id1.replace(
    /[\{\}\[\]\/?,;:|\)*~`!^\+<>@\#$%&\\\=\(\'\"]/gi,
    ""
  );
  const new_id3 = new_id2.replace(/(\.){2,}/gi, ".");
  let new_id4 = new_id3;
  if (new_id3[0] === ".") new_id4 = new_id3.substring(1);
  if (new_id4[new_id4.length - 1] === ".")
    new_id4 = new_id4.substring(0, new_id4.length - 1);
  const new_id5 = new_id4.length === 0 ? "a" : new_id4;
  let new_id6 = new_id5;
  if (new_id5.length >= 16) new_id6 = new_id5.substring(0, 15);
  if (new_id6[new_id6.length - 1] === ".")
    new_id6 = new_id6.substring(0, new_id6.length - 1);
  console.log(new_id6);
  let new_id7 = new_id6;
  if (new_id6.length == 2) new_id7 = new_id6 + new_id6[1];
  if (new_id6.length == 1) new_id7 = new_id6 + new_id6 + new_id6;
  console.log(new_id7);
  return new_id7;
};
