function arrangeWords(text: string): string {
  const words: string[] = text.split(" ");

  words[0] = words[0][0].toLowerCase() + words[0].slice(1);
  words.sort((w1, w2) => w1.length - w2.length);
  words[0] = words[0][0].toUpperCase() + words[0].slice(1);

  return words.join(" ");
}
