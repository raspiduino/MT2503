#!/usr/local/bin/perl
$OUTPUT = shift(@ARGV);
$ITEM = shift(@ARGV);
@INPUT = @ARGV;

foreach my $file (@INPUT) {
  if ((-e $file) && (open(FILE_HANDLER,"<$file")))
  {
    while(<FILE_HANDLER>) {
      if($_ !~ /^\s/) {
        if($_ !~ /.+\s$/) {
          push @output, $_;
        } else {
          chomp;
          push @output, $_;
        }
      }
    }
    close(FILE_HANDLER);
  }
  else
  {
    print STDERR "[ERROR] Fail to open $file\n";
  }
}

my %saw;
@output = grep (!$saw{$_}++, @output);
open(W,">>$OUTPUT") or die "Fail to write $OUTPUT\n";
foreach my $def (@output)
{
	print W "$ITEM$def\n";
}
close(W);

